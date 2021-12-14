#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>



struct houses
{
    std::string elf;
    houses* nextHouse;
    houses* prevHouse;
};

class SmallBranch
{
    houses* firstHouseSmallBranch;
    houses* lastHouseSmallBranch; 
    houses* currentHouseSmallBranch;
    houses* tmpSB;

    public:
    SmallBranch(int countHouseSmallBranch)
    {
        std::cout << "Insert elf's name in house" << 0 << ":\n";
        std::string name;
        std::cin >> name;
        firstHouseSmallBranch = new houses;
        firstHouseSmallBranch->nextHouse = nullptr;
        firstHouseSmallBranch->prevHouse = nullptr;
        firstHouseSmallBranch->elf = name;
        currentHouseSmallBranch = firstHouseSmallBranch;
        if (countHouseSmallBranch > 1)
        {
            for (int i = 1; i < countHouseSmallBranch; ++i)
            {
                std::cout << "Insert elf's name in house" << i << ":\n";
                std::string name;
                std::cin >> name;
                tmpSB = new houses;
                currentHouseSmallBranch->nextHouse = tmpSB;
                tmpSB->prevHouse = currentHouseSmallBranch;
                currentHouseSmallBranch = tmpSB;
                currentHouseSmallBranch->elf = name;
                currentHouseSmallBranch->nextHouse = nullptr;
            }
            lastHouseSmallBranch = currentHouseSmallBranch;
        }
    }

    void showElfs()
    {
        currentHouseSmallBranch = firstHouseSmallBranch;
        while (currentHouseSmallBranch->nextHouse)
        {
            std::cout << currentHouseSmallBranch->elf << "\n";
            currentHouseSmallBranch = currentHouseSmallBranch->nextHouse;
        }
        std::cout << currentHouseSmallBranch->elf << "\n";
    }
    ~SmallBranch()
    {
        currentHouseSmallBranch = firstHouseSmallBranch;
        while (currentHouseSmallBranch->nextHouse)
        {
            tmpSB = currentHouseSmallBranch->nextHouse;
            delete currentHouseSmallBranch;
            currentHouseSmallBranch = tmpSB;
        }
        delete currentHouseSmallBranch;
    }
};

class BigBranch
{
    std::vector<SmallBranch> bigBranch();
    int countSmallBranch;
    int countHouseBigBranch;

    public:
        void pushToVector()
        {
            bigBranch();
        }    

        BigBranch(int a_countSmallBranch, int a_countHouseBigBranch)
        {
            countSmallBranch = a_countSmallBranch;
            countHouseBigBranch = a_countHouseBigBranch;
            
        }

};

class Three
{

};


class Forrest
{
    public:

    Three threes[5];
};

int main()
{
   // Forrest myForrest;
    std::srand(std::time(nullptr));
    int cBranch = (std::rand() % 2 + 2);
    int bBranch = (std::rand() % 3 + 3);
    std::cout << cBranch << "\n";
    SmallBranch myBranch(cBranch);
    myBranch.showElfs();

}
