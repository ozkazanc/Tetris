/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
# include "helperFunctions.h"

//globals:

//char field[]
//const int field_height
//const int field_width

//std::string blocks[7]

void printField(){
    for(int i = 0; i < field_height; i++){
        for(int j = 0; j < field_width;j++)
            std::cout << field[i*field_width + j];
        std::cout << std::endl;
    }
}
void initField(){
	for (int i = 0; i < field_height; i++){
		for (int j = 0; j < field_width; j++)
			field[i*field_width + j] = (j == 0 || j == field_width - 1 || i == field_height - 1) ? '#' : ' ';
    }
}
void printBlock(const std::string& block){
    for(unsigned int i = 0; i < block.length();i++){
        if(i % 4 == 0) std::cout << std::endl;
        std::cout << block[i];       
    }
}