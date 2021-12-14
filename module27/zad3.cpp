#include <iostream>
#include <ctime>
#include <stdlib.h>

class Worker
{
    int id = 0;
    char typeWork = 'X';

    public:

    bool itsWork = false;

    void setWork()
    {
        int i = rand() % 3;
        if (i == 0)
            typeWork = 'A';
        else if (i == 1)
            typeWork = 'B';
        else if (i == 2)
            typeWork = 'C';
        itsWork = true;      
    }

    void setId(int in_id)
    {
        id = in_id;
    }

    void showWork()
    {
        std::cout << "Worker id: " << id << "\ttypeWork: " << typeWork << "\n";
    }
};

class Manager
{
    int id = 0;
    int task = 0;
    int countTask = 0;
    int countWorkers = 0;
    bool allWorkersWork = false;
    Worker* myWorkers;

    public:

    Manager()
    {
        std::cout << "New manager\n";
        std::cout << "Insert count workers: ";
        std::cin >> countWorkers;
        myWorkers = new Worker[countWorkers];
        for (int i=0; i < countWorkers; ++i)
        {
            myWorkers[i].setId(i);
        }
    }

    void setId(int in_id)
    {
        id = in_id;
    }

    void setWork(int identificator)
    {
        int checkSum = 0;
        task = identificator + id;
        std::cout << task << " ";
        std::srand(task);
        countTask = rand() % countWorkers + 1;
        std::cout << countTask << "\n";
        for (int i=0; (i < countTask) && !allWorkersWork && (i < countWorkers); ++i)
        {
            if (!myWorkers[i].itsWork)
                myWorkers[i].setWork();
            else
                countTask++;
        }
        for (int i=0; i < countWorkers; ++i)
        {
            if (!myWorkers[i].itsWork)
                break;
            checkSum++;
        }
        if (checkSum == countWorkers)
            allWorkersWork = true;
    }

    void showWork()
    {
        std::cout << "Manager " << id << "\tCount workers: " << countWorkers << "\n";
        for (int i=0; i < countWorkers; ++i)
            myWorkers[i].showWork();
    }

    void checkManager()
    {
        std::cout << "Its alive " << id << "\n";
    }

    bool workersWork()
    {
        return allWorkersWork;
    }
};

class Director
{
    int identificator = 0;
    int countManagers = 0;
    Manager* myManagers;

    public:

    Director()
    {
        std::cout << "Insert count Managers: ";
        std::cin >> countManagers;
        myManagers = new Manager[countManagers];
        for (int i=0; i < countManagers; ++i)
        {
            myManagers[i].setId(i);
        }   
    }

    void checkMyManagers()
    {
        for (int i=0; i < countManagers; ++i)
        {
            myManagers[i].checkManager();
        }
    }

    void setIdentificator(int &id)
    {
        identificator = id;
        for (int i=0; i < countManagers; ++i)
        {
            myManagers[i].setWork(identificator);
        }
    }

    void showWork()
    {
        std::cout << "Director have " << countManagers << "\n";
        for (int i=0; i < countManagers; ++i)
            myManagers[i].showWork();
    }

    bool allWorkersWork()
    {
        int checkWork = 0;
        for (int i=0; i < countManagers; ++i)
        {
            if (myManagers[i].workersWork())
                ++checkWork;
        }
        if (checkWork == countManagers)
            return true;
        else
            return false;
    }
};

int main() {
    int inp = 0;
    bool allWorkersWork = false;
    Director myDirector;
    myDirector.checkMyManagers();

    while (!allWorkersWork)
    {
        std::cout << "Insert edict:\n";
        std::cin >> inp;
        myDirector.setIdentificator(inp);
        myDirector.showWork();
        allWorkersWork = myDirector.allWorkersWork();
    }
    std::cout << "All workers work!\n";
} 
