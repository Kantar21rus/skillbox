#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <unistd.h>

enum status {
    inTravel = 0,
    wait = 1,
    loading = 2,
    depart = 3
};

std::mutex start;
std::mutex station;
std::mutex initTrain;
int countdown = 3;

struct trainStat 
{
    std::string route = "route #";
    int travelTime = 0;
    int status = inTravel;
    
};


class Train 
{
    trainStat myTS;

    public:
    Train(char routChar, int tTime)
    {
        myTS.route[6] = routChar;
        myTS.travelTime = tTime;
    }

    int getTravelTime()
    {
        return myTS.travelTime;
    }

    std::string getName()
    {
        return myTS.route;
    }

    void changeStatus(int status)
    {
        myTS.status = status;
    }
};

void addTrain()
{
    char routeChar;
    int travelTime = 0;
    initTrain.lock();
    std::cout << "Insert character route's name: ";
    std::cin >> routeChar;
    std::cout << "Insert time to travel: ";
    std::cin >> travelTime;
    initTrain.unlock();
    countdown--;
    for(;countdown != 0;)
    {
        usleep(100);
    }
    Train* myTrain = new Train(routeChar, travelTime);
    std::this_thread::sleep_for(std::chrono::seconds(myTrain->getTravelTime()));
    myTrain->changeStatus(wait); 
    std::cout << myTrain->getName() << " waiting\n";
    station.lock();
    myTrain->changeStatus(loading);
    std::cout << myTrain->getName() << " input station\n";
    std::string comand ="";
    std::cout << "Input 'depart':\n";
    while (comand != "depart")
    {
        std::cin >> comand;
    }
    myTrain->changeStatus(depart);
    station.unlock();
    std::cout << myTrain->getName() << " complete\n";
}

int main()
{
    start.lock();
    std::thread roat1(addTrain);
    std::thread roat2(addTrain);
    std::thread roat3(addTrain);
    start.unlock();
    roat1.join();
    roat2.join();
    roat3.join();
}

