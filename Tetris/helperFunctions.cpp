/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
# include "helperFunctions.h"

//globals:

//wchar_t field[]
//const int field_height
//const int field_width

//std::wstring blocks[7]

void PrintField(){
    for(int i = 0; i < field_height; i++){
        for(int j = 0; j < field_width;j++)
            std::cout << field[i*field_width + j];
        std::cout << std::endl;
    }
}
void InitField(){
	for (int i = 0; i < field_height; i++){
		for (int j = 0; j < field_width; j++)
			field[i*field_width + j] = (j == 0 || j == field_width - 1 || i == field_height - 1) ? L'#' : L' ';
    }
}
void PrintBlock(const std::string& block){
    for(unsigned int i = 0; i < block.length();i++){
        if(i % 4 == 0) std::cout << std::endl;
        std::cout << block[i];       
    }
}
int Rotate(int px, int py, int r){
	switch (r % 4){
	case 0:
		return(py * 4 + px);		//0 degrees
	case 1:
		return(12 + py - 4 * px);	//90 degrees
	case 2:
		return(15 - 4 * py - px);	//180 degrees
	case 3:
		return(3 - py + 4 * px);	//270 degrees
	default:
		return -1;
	}
}
bool DoesBlockFit(int block, int r, int posX, int posY){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			int blockIndex = Rotate(i, j, r);

			int fieldIndex = (posY + j) * field_width + (posX + i);

			if (posX + i >= 0 && posX + i < field_width){
				if (posY + j >= 0 && posY + j < field_height){
					if (blocks[block][blockIndex] != L' ' && field[fieldIndex] != L' '){
						return false;
					}
				}
			}
		}
	}
	return true;
}