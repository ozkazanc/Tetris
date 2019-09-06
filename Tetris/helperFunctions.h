/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   helperFunctions.h
 * Author: Doruk.Ozkazanc
 *
 * Created on 29 Ocak 2019 Salı, 19:41
 */

#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <string>

extern const int field_height;
extern const int field_width;
extern wchar_t field[];
extern std::wstring blocks[7];

void PrintField();
void InitField();
void PrintBlock(const std::string& block);
int Rotate(int px, int py, int r);
bool DoesBlockFit(int block, int r, int posX, int posY);

#endif /* HELPERFUNCTIONS_H */

