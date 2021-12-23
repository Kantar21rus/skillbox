#include <bits/types/time_t.h>
#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>

enum {
    countSwimmer = 6
};

std::mutex outMutex;

struct oneSwimmer
{
    std::string name = "";
    double speed = 0;
    double remained = 100;
    bool heFinish = false;
    std::time_t startTime = 0;
    std::time_t finishTime = 0;
};

class Swimmer
{   
    oneSwimmer inCSw;
    std::thread* line;

    public:

    Swimmer()
    {
        std::cout << "Insert name:\n";
        std::cin >> inCSw.name;
        std::cout << "Insert his speed:\n";
        std::cin >> inCSw.speed;
    }
    
    void setStartTime(std::time_t s_time)
    {
        inCSw.startTime = s_time;
    }

    void setFinishTime()
    {
        inCSw.finishTime = std::time(nullptr);
    }

    oneSwimmer& getSwimmer()
    {
        return inCSw;
    }

    oneSwimmer getSwimmer2()
    {
        return inCSw;
    }

    double getSwimTime()
    {
         return inCSw.finishTime - inCSw.startTime;
       // return std::difftime(inCSw.finishTime, inCSw.startTime);
    }
 
    double getRemained()
    {
        return inCSw.remained;
    }

};

void startSwim(oneSwimmer *threadSwimmer)
    {
        threadSwimmer->startTime = std::time(nullptr);
        outMutex.lock();
        std::cout << threadSwimmer->name << "\t" << threadSwimmer->speed << "\n";
        std::cout << "thread id: " << std::this_thread::get_id() << "\n";
        outMutex.unlock();
        while (!threadSwimmer->heFinish)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            threadSwimmer->remained -= threadSwimmer->speed;
            if (threadSwimmer->remained <= 0.01)
            {
                threadSwimmer->finishTime = std::time(nullptr);
                threadSwimmer->heFinish=true;
                outMutex.lock();
                std::cout << "Swimmer " << threadSwimmer->name << " finished!\n";
                outMutex.unlock();
            }
            else 
            {
                outMutex.lock();
                std::cout << "For swimmer " << threadSwimmer->name << " remaining: " << threadSwimmer->remained << " meters to the finish line\n";
                outMutex.unlock();
            }
        }
    }
int main()
{
    std::cout << "Main thread id: " << std::this_thread::get_id() << "\n";
    Swimmer mySwimmer[countSwimmer];
    oneSwimmer tmpSwimmer, sThreadSwimmer;
    
    std::thread* threadDirector[countSwimmer];

    for (int i=0; i<countSwimmer; ++i)
    {
        threadDirector[i] = new std::thread(startSwim, &(mySwimmer[i].getSwimmer()));
    }

    for (int i=0; i <countSwimmer; ++i)
    {
        threadDirector[i]->join();
        delete threadDirector[i];
    }
    
    for(int i=0; i<countSwimmer; ++i)
    {
        for(int j=0; j<(countSwimmer-1); ++j)
        {
            if (mySwimmer[j].getSwimTime() > mySwimmer[j+1].getSwimTime())
            {
                Swimmer tmp = mySwimmer[j];
                mySwimmer[j] = mySwimmer[j+1];
                mySwimmer[j+1] = tmp;
            }    
        }
    }
    
    for (int i=0; i<countSwimmer; ++i)
    {
        tmpSwimmer = mySwimmer[i].getSwimmer2();
        std::cout << "Swimmer " << tmpSwimmer.name << "\tSwim time: " << tmpSwimmer.finishTime - tmpSwimmer.startTime  << "\n";
    }

}
