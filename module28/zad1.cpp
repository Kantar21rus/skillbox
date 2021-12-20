#include <iostream>
#include <ctime>
#include <thread>

enum {
    countSwimmer = 2
};

struct oneSwimmer
{
    std::string name = "";
    double speed = 0;
    double remained = 100;
    bool heFinish = false;
};

void startSwim(oneSwimmer threadSwimmer)
{
    std::cout << threadSwimmer.name << "\t" << threadSwimmer.speed << "\n";
    std::cout << "thread id: " << std::this_thread::get_id() << "\n";
    while (!threadSwimmer.heFinish)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        threadSwimmer.remained -= threadSwimmer.speed;
        if (threadSwimmer.remained <= 0.01)
       {
            threadSwimmer.heFinish=true;
            std::cout << "Swimmer " << threadSwimmer.name << " finished!\n";
        }
        else 
        {
            std::cout << "For swimmer " << threadSwimmer.name << " remaining: " << threadSwimmer.remained << " meters to the finish line\n";
        }
    }
}

class Swimmer
{   
    oneSwimmer inCSw;
    std::thread* line;

    public:
    std::time_t startTime = 0;
    std::time_t finishTime = 0;

    Swimmer()
    {
        std::cout << "Insert name:\n";
        std::cin >> inCSw.name;
        std::cout << "Insert his speed:\n";
        std::cin >> inCSw.speed;
    }
    
    oneSwimmer getSwimmer()
    {
        return inCSw;
    }

    void startThread()
    {
        line=new std::thread(startSwim, inCSw);
    }
    void Join()
    {
        line->join();
        delete line;
    }
    
    double getRemained()
    {
        return inCSw.remained;
    }
};

int main()
{
    std::cout << "Main thread id: " << std::this_thread::get_id() << "\n";
    Swimmer mySwimmer[countSwimmer];
    oneSwimmer sThreadSwimmer;

    for (int i=0; i<countSwimmer; ++i)
        mySwimmer[i].startThread();

    for (int i=0; i<countSwimmer; ++i)
    {
        mySwimmer[i].Join();
    }
    
    oneSwimmer* pos[countSwimmer];

    for (int i=0; i<countSwimmer; ++i)
    {
        *pos[i] = mySwimmer[i].getSwimmer();
    }
    for (int i=0; i<countSwimmer; ++i)
    {
        oneSwimmer* slowest = pos[0];
        oneSwimmer* tmp;
        for (int j=0; i<countSwimmer; ++i)
        {            
            if (pos[j]->remained > slowest->remained)
            {
                tmp = slowest;
                slowest = pos[j];
            }
        }    
    }
}
