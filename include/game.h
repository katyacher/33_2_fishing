#include <exception>


class boot: public std::exception{
    const char* what() const noexcept override{
        return "Loose! You caught a boot";
    }
};

class fish: public std::exception{
    const char* what() const noexcept override{
        return "Win! You caught a fish";
    }
};

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