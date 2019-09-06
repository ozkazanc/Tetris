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
#include "helperFunctions.h"


//Tetris blocks and playing field
const int field_width = 12;
const int field_height = 24;
std::string blocks[7];
char field[field_height*field_width];

int main() {
    blocks[0] = "  x   x   x   x "; //I block
    blocks[1] = "     xx  xx     "; //O block
    blocks[2] = " x   xx   x     "; //S block
    blocks[3] = "  x  xx  x      "; //Z block
    blocks[4] = "      x  xxx    "; //T block
    blocks[5] = " x   x   xx     "; //L block
    blocks[6] = "  x   x  xx     "; //J block

    //printField(field,FIELD_HEIGHT,FIELD_WIDTH);
	initField();
	printField();
    printBlock(blocks[0]);
    printBlock(blocks[1]);
    printBlock(blocks[2]);
    printBlock(blocks[3]);
    printBlock(blocks[4]);
    printBlock(blocks[5]);
    printBlock(blocks[6]);
    
    
    //std::cout << block[1] << std::endl;
	std::cin.get();
    return 0;
}

