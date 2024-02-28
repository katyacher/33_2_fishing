#include <stdexcept>
#include <iostream>
#include <ctime>
#include "game.h"

Game::Game(){
    int field_size = sizeof(field)/sizeof(field[0]);

    for(int i = 0; i < field_size; ++i){
        field[i] = Item::EMPTY;
    }

    std::srand(std::time(nullptr));
    field[std::rand() % 9] = Item::FISH;


    int i = 0;
    while(i < boot_count){
        int item = std::rand()% 9;
        if(field[item] == Item::EMPTY){
            field[item] = Item::BOOT;
            ++i;
        } 
    }

}

void Game::fishing(int sector){
    int field_size = sizeof(field)/sizeof(field[0]);

    if(sector < 0 || sector >= field_size ){
        throw std::out_of_range("Fishing sector must be 0 to 8");
    }

    if(field[sector] == Item::FISH)
        throw Item::FISH;
    
    if(field[sector] == Item::BOOT)
        throw Item::BOOT;
    
    if(field[sector] == Item::EMPTY)
    {
        ++number_of_attempts;
        throw std::runtime_error("There are no fish here, try again");
    }
}

int Game::attempts(){
    return number_of_attempts;
}
	

