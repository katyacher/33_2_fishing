#pragma once

enum class Item{
    BOOT,
    FISH,
    EMPTY
};

class Game{
    Item field[9];
    int number_of_attempts = 1;
    int boot_count = 3;

public:
    Game();

    void fishing(int sector);

    int attempts();
};