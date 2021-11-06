#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>

int main()
{
    std::time_t now;
    int min;
    int sec;
    std::time_t timer;
    std::tm* timeToday;
    double dif;
    std::time_t tmp;

    std::cout << "Insert timer in format: \"min sec\"\n";
    std::cin >> min >> sec;
    if (min > 60 || min < 0 || sec > 60 || sec < 0)
    {
        std::cout << "Wrong timer\n";
        return 1;
    }
    now = std::time(nullptr);
    timer = now;
    timer += (min * 60 + sec);
    for(;timer >= now;)
    {
        now = std::time(nullptr);
        dif = difftime(timer, now);
        tmp = (int) dif;
        timeToday = std::localtime(&tmp);
        std::cout << std::put_time(timeToday, "%M:%S\n");
        usleep(900000);
    }
    std::cout << "Timer over!\n";

   
} 
