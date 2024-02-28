#include <iostream>
#include "game.h"

int main(int, char**){
    std::cout << "Hello, from 33_2_fishing!\n";

    bool fishing = true;
    Game game;

    while(fishing){
        int sector;
        std::cout << "Enter a number of fishing sector from 0 to 8: ";
        std::cin >> sector;

        if(std::cin.fail()) {
            std::cin.clear();
            std::string str;
            std::getline(std::cin, str);
            std::cout << "Not a number" << std::endl;
            continue;
        }

        try{
            game.fishing(sector);
        } catch(const Item &x){
            if(x == Item::FISH){
                std::cout << "Win! You caught a fish in " << game.attempts() << " attemps." << std::endl;
                fishing = false;
            }
            if(x == Item::BOOT){
                std::cout << "Loose...you caught a boot" << std::endl;
                fishing = false;
            }
            
        } catch(const std::runtime_error &x){
            std::cout << x.what() << std::endl;
        } catch(const std::exception &x){
            std::cout << x.what() << std::endl;
        }
    }
    std::cout << "Exit" << std::endl;
    return 0;
}
