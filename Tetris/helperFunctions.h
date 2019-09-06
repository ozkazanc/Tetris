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

void printField(const char field[24][12], int height, int width);
void fieldInit(char field[24][12], int height, int width);
void printBlock(const std::string& block);

#endif /* HELPERFUNCTIONS_H */

