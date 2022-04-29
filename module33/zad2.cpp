#include <iostream>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <stdlib.h>

enum {
    empty = 0,
    boot = 1,
    fish = 2
};

class CaughtBoot: public std::exception {
    const char*what() const noexcept override {
        return "You caught a boot";
    }
};

class CaughtFish: public std::exception {
    const char*what() const noexcept override {
        return "You caught a fish";
    }
};

struct field {
    int whatHave = empty;
    bool wasOpen = false;
    char symbol = '~';
};

class Lake {
    field lakeField[9];
    int points = 0;

    public: 

    Lake() {
        int tmp = std::rand()%9;
        lakeField[tmp].whatHave = fish;
        lakeField[tmp].symbol = 'F';
        for (int i=0; i < 3 ;++i) {
            tmp = std::rand()%9;
            if (lakeField[tmp].whatHave == empty) {
                lakeField[tmp].whatHave = boot;
                lakeField[tmp].symbol = 'B';
            } else {
                --i;
            }
        }
    }

    void showLake() {
        for (int i=0; i < 9; ++i) {
            if ( i%3 == 2) {
                if (lakeField[i].wasOpen) {
                    std::cout << lakeField[i].symbol;
                } else {
                    std::cout << '~';
                }
                std::cout << "\n";
            } else {
                if (lakeField[i].wasOpen) {
                    std::cout << lakeField[i].symbol;
                } else {
                    std::cout << '~';
                }
            }
        }
    }

    void fishing(int place) {
        lakeField[place].wasOpen = true;
        if (lakeField[place].whatHave == fish) {
            ++points;
            throw CaughtFish();
        } else if (lakeField[place].whatHave == boot) {
            --points;
            throw CaughtBoot();
        }
    }

    void showPoints() {
        std::cout << "you points: " << points << "\n";
    }

    int& getPoints() {
        return points;
    }
};

int main() {
    std::srand(std::time(nullptr));
    Lake myLake;
    myLake.showLake();
    for(;;) {
        int i;
        std::cout << "Enter the place where you want to cast a fishing rod: ";
        std::cin >> i;
        try {
            myLake.fishing(i);
        } catch (CaughtFish ) {
            myLake.showLake();
            if (myLake.getPoints() == 1) {
                std::cerr << "You caught a fish, you win" << "\n";
            } else {
                std::cerr << "You caught a fish, game finish with points: " << myLake.getPoints() << "\n";
            }
            return 0;
        } catch (CaughtBoot) {
            std::cerr << "You caught a boot, try again" << "\n";
        }
        myLake.showLake();
    }
}
