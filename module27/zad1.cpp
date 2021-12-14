#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class House
{
    public: 
        std::string elfName = "";
        bool itsEmpty = false;

        House()
        {
            std::cout << "Insert elf's name: ";
            std::cin >> elfName;
            if (elfName == "None")
                itsEmpty = true;
        }
};

class SmallBranch
{
    int idSB = 0;
    House myHouse;

    public:

    SmallBranch* next;

    SmallBranch(int b_id)
    {
        idSB = b_id;
        std::cout << "ID: " << idSB << "\n";
        
    }

    bool houseEmpty()
    {
        return myHouse.itsEmpty;
    }

    std::string sayNameSB()
    {
        return myHouse.elfName;
    }

    void searchElfS(std::string &s_name, bool &s_itsFind)
    {
        if (s_name == myHouse.elfName)
            s_itsFind = true;
        else
            s_itsFind = false;
    }
};

class BigBranch
{
    int idBB = 0;
    int countSmallB = 0;
    House myHouse;
    SmallBranch* startSB;
    SmallBranch* currentSB;
    SmallBranch* tmpSB;
    
    public:

    BigBranch* next;

    BigBranch(int a_id)
    {

        idBB = a_id;
        std::cout << "Big Branch ID: " << idBB << "\n";
        countSmallB = rand() % 2 + 2;
        std::cout << "Count small branch: " << countSmallB << "\n";
        startSB = new SmallBranch(0);
        currentSB = startSB;
        for (int i=1; i < countSmallB; ++i)
        {
            tmpSB = new SmallBranch(i);
            currentSB->next = tmpSB;
            currentSB = tmpSB;
        }
    }
    
    void showElfs()
    {
        if (!myHouse.itsEmpty) 
            std::cout << myHouse.elfName << "\n";
        currentSB = startSB;
        while (currentSB->next)
        {
            if (!currentSB->houseEmpty()) 
                std::cout << currentSB->sayNameSB()<< "\n";
            tmpSB = currentSB->next;
            currentSB = tmpSB;
        }
        if (!currentSB->houseEmpty()) 
            std::cout << currentSB->sayNameSB()<< "\n";
    }

    void searchElfB(std::string &b_name, bool b_itsFind)
    {
        if (myHouse.elfName == b_name) 
        {
            b_itsFind = true;
            showElfs();
            return;
        }
        currentSB = startSB;
        for (int i=0; i<countSmallB; ++i)
        {
            currentSB->searchElfS(b_name, b_itsFind);
            if (b_itsFind)
            {
                showElfs();
                return;
            }
            if (currentSB->next != nullptr)
                currentSB = currentSB->next; 
        }
    }
};

class Three
{
    int countBigB = 0;
    BigBranch* startBB;
    BigBranch* currentBB;
    BigBranch* tmpBB;
    public:

    Three()
    {
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
        countBigB = rand() % 3 + 3;
        std::cout << "Count big branch: " << countBigB << "\n";
        std::cout << "---------------------------------------------\n";
        startBB = new BigBranch(0);
        currentBB = startBB;
        for (int i=1; i < countBigB; ++i)
        {
            std::cout << "---------------------------------------------\n";
            tmpBB = new BigBranch(i);
            currentBB->next = tmpBB;
            currentBB = tmpBB;
        }
    }
    
    void searchElfT(std::string &t_name, bool &t_itsFind)
    {
        currentBB = startBB;
        for (int i=0; i<countBigB; ++i)
        {
            currentBB->searchElfB(t_name, t_itsFind);
            if (t_itsFind)
            {
                return;
            }
            if (currentBB->next != nullptr)
                currentBB = currentBB->next; 
        }
    }

};


int main()
{
    std::srand(std::time(nullptr));
    Three myThree[5];
    std::string elfFind = "";
    bool itsFind = false;
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "Insert name to find: ";
    std::cin >> elfFind;
    for (int i=0; i<5; ++i)
    {
        std::cout << "Search in three " << i << "\n";
        myThree[i].searchElfT(elfFind, itsFind);
        if (itsFind)
            break;
        else
            std::cout << "In three " << i << " haven't this elf\n";
    }
}
