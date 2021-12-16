#include <iostream>
#include <ctime>
#include <thread>


class Swimmer
{   
    public:
    int id = 0;
    std::string name = "";
    double speed = 0;
    bool heFinish = false;
    std::time_t startTime = 0;
    std::time_t finishTime = 0;
    double remained = 100;

    Swimmer()
    {
        std::cout << "Insert name:\n";
        std::cin >> name;
        std::cout << "Insert his speed:\n";
        std::cin >> speed;
    }
    
    static void startSwim()
    {

    }

};

int main()
{
    Swimmer mySwimmer[6];
    for (int i=0; i<6; ++i)
    {
       mySwimmer[i].startSwim();
    } 

    std::thread line1(mySwimmer[0].startSwim);

}
