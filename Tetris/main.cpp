/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Doruk.Ozkazanc
 *
 * Created on 29 Ocak 2019 Salı, 19:20
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <Windows.h>

#include "helperFunctions.h"


//Tetris blocks and playing field
const int field_width = 12;
const int field_height = 24;
std::wstring blocks[7];
wchar_t field[field_height*field_width];
int nScreenWidth = 80;			// Console Screen Size X (columns)
int nScreenHeight = 30;			// Console Screen Size Y (rows)
int main() {
	// Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

    blocks[0] = L"  x   x   x   x "; //I block
    blocks[1] = L"     xx  xx     "; //O block
    blocks[2] = L" x   xx   x     "; //S block
    blocks[3] = L"  x  xx  x      "; //Z block
    blocks[4] = L"      x  xxx    "; //T block
    blocks[5] = L" x   x   xx     "; //L block
    blocks[6] = L"  x   x  xx     "; //J block

	InitField();
	
	//Game loop
	int score = 0;

	int pieceCount = 0;
	int tickCount = 0;
	int playSpeed = 20;
	bool forceDown = false;

	int bKey[4];
	int currentBlock = 0;
	int currentR = 0;
	int currentX = field_width / 2;
	int currentY = 0;
	bool keyHold = false;
	bool rotateHold = false;
	bool bGameOver = false;

	std::vector<int> vLines;
	while (!bGameOver){
		//spawn block if not placed
		
		//Timing ==========================================
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Small Step = 1 Game Tick
		tickCount++;
		forceDown = (tickCount == playSpeed);

		// Input ==========================================
		
		for (int k = 0; k < 4; k++)								// R   L   D Z
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;

		// Game Logic =====================================
		
		// Handle player movement
		currentX += (bKey[0] && DoesBlockFit(currentBlock, currentR, currentX + 1, currentY)) ? 1 : 0;
		currentX -= (bKey[1] && DoesBlockFit(currentBlock, currentR, currentX - 1, currentY)) ? 1 : 0;
		currentY += (bKey[2] && DoesBlockFit(currentBlock, currentR, currentX, currentY + 1)) ? 1 : 0;
		
		// Rotate,but stop latching
		if (bKey[3])
		{
			currentR += (rotateHold && DoesBlockFit(currentBlock, currentR + 1, currentX, currentY)) ? 1 : 0;
			rotateHold = false;
		}
		else
			rotateHold = true;

		if (forceDown){
			tickCount = 0;
			if (pieceCount % 10) playSpeed--;

			if (DoesBlockFit(currentBlock, currentR, currentX, currentY + 1)){
				currentY++;
			}
			else{
				// Lock the piece in place
				for (int px = 0; px < 4; px++)
					for (int py = 0; py < 4; py++)
						if (blocks[currentBlock][Rotate(px, py, currentR)] != L' ')
							field[(currentY + py) * field_width + (currentX + px)] = L'x';

				// Check for lines
				for (int py = 0; py < 4; py++)
					if (currentY + py < field_height - 1)
					{
						bool bLine = true;
						for (int px = 1; px < field_width - 1; px++)
							bLine &= (field[(currentY + py) * field_width + px]) != L' ';

						if (bLine)
						{
							// Remove Line, set to =
							for (int px = 1; px < field_width - 1; px++)
								field[(currentY + py) * field_width + px] = L'=';
							vLines.push_back(currentY + py);
						}
					}
				//Increment the score
				score += 25;
				if (!vLines.empty())	score += (1 << vLines.size()) * 100;

				// Pick a new block
				currentX = field_width / 2;
				currentY = 0;
				currentR = 0;
				currentBlock = rand() % 7;

				// If piece does not fit straight away, game over!
				bGameOver = !DoesBlockFit(currentBlock, currentR, currentX, currentY);
			}

		}
		// Display ========================================

		// Draw Field
		for (int x = 0; x < field_width; x++)
			for (int y = 0; y < field_height; y++)
				screen[(y + 2)*nScreenWidth + (x + 2)] = field[y*field_width + x];

		// Draw Current Piece
		for (int px = 0; px < 4; px++)
			for (int py = 0; py < 4; py++)
				if (blocks[currentBlock][Rotate(px, py, currentR)] != L' ')
					screen[(currentY + py + 2)*nScreenWidth + (currentX + px + 2)] = blocks[currentBlock][Rotate(px, py, currentR)];

		swprintf_s(&screen[2 * nScreenWidth + field_width + 6], 16, L"SCORE: %8d", score);

		if (!vLines.empty())
		{
			// Display Frame (cheekily to draw lines)
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
			std::this_thread::sleep_for(std::chrono::milliseconds(400)); // Delay a bit

			for (auto &v : vLines)
				for (int px = 1; px < field_width - 1; px++)
				{
					for (int py = v; py > 0; py--)
						field[py * field_width + px] = field[(py - 1) * field_width + px];
					field[px] = L' ';
				}

			vLines.clear();
		}


		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}
    
	CloseHandle(hConsole);
	std::cout << "Game Over!! Score:" << score << std::endl;
	std::cin.get();
    return 0;
}

