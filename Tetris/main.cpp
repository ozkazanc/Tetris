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

#define FIELD_HEIGHT 24
#define FIELD_WIDTH 12

//Tetris blocks and playing field
std::string block[7];
char field[FIELD_HEIGHT][FIELD_WIDTH];

int main() {
    block[0] = "  x   x   x   x "; //I block
    block[1] = "     xx  xx     "; //O block
    block[2] = " x   xx   x     "; //S block
    block[3] = "  x  xx  x      "; //Z block
    block[4] = "      x  xxx    "; //T block
    block[5] = " x   x   xx     "; //L block
    block[6] = "  x   x  xx     "; //J block

    //printField(field,FIELD_HEIGHT,FIELD_WIDTH);
    fieldInit(field,FIELD_HEIGHT,FIELD_WIDTH);
    printField(field,FIELD_HEIGHT,FIELD_WIDTH);
    printBlock(block[0]);
    printBlock(block[1]);
    printBlock(block[2]);
    printBlock(block[3]);
    printBlock(block[4]);
    printBlock(block[5]);
    printBlock(block[6]);
    
    
    //std::cout << block[1] << std::endl;
    
    return 0;
}

