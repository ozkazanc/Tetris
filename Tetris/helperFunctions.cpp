/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
# include "helperFunctions.h"

void printField(const char field[24][12], int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width;j++)
            std::cout << field[i][j];
        std::cout << std::endl;
    }
}
void fieldInit(char field[24][12], int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width;j++)
            field[i][j] = (j == 0 || j == width - 1 || i == height - 1) ? '#' : ' '; 
    }
}
void printBlock(const std::string& block){
    for(int i = 0; i < block.length();i++){
        if(i % 4 == 0) std::cout << std::endl;
        std::cout << block[i];       
    }
}