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


    Swimmer(std::string &in_name, double &in_speed)
    {
        name = in_name;
        speed = in_speed;
    }
};

int main()
{
    Swimmer mySwimmer[6];
    std::string name = "";
    double speed = 0;
        std::cout << "Insert name swimmer" << i << ":\n";
        std::cin >> name;
        std::cout << "Insert his speed:\n";
        std::cin >> speed;
        Swimmer(name, speed);

}
