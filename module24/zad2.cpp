#include <iostream>
#include <ctime>
#include <iomanip>

struct friend_date
{
    std::string name;
    std::time_t birtday = 1000000;
    int day;
    int month;
    int year;
    int yday;
};

int main() {
    std::time_t today = std::time(nullptr);
    std::tm* timeToday;
    timeToday = std::localtime(&today);
    int countFr = 0;

    struct friend_date friends[100];
    std::string input = "";
    for (; countFr < 100; ++countFr)
    {
        std::cin >> input;
        if (input == "end")
            break;
        friends[countFr].name = input;
        std::cin >> std::get_time(timeToday, "%Y/%m/%d");
        friends[countFr].birtday = mktime(timeToday);
        timeToday = std::localtime(&friends[countFr].birtday);
        friends[countFr].day = timeToday->tm_mday;
        friends[countFr].month = timeToday->tm_mon;
        friends[countFr].year = timeToday->tm_year;
        friends[countFr].yday = timeToday->tm_yday;
    }
    
    today = std::time(nullptr);
    timeToday = std::localtime(&today);

    int minDay = 365;
    int yday  = 0;
    for (int i=countFr; i >= 0; --i)
    {
        int tmp = friends[i].yday - timeToday->tm_yday;
        if (tmp >= 0 && tmp < minDay)
        {
            minDay = tmp;
            yday = friends[i].yday;
        }
    }

    for (int i=countFr; i>= 0; --i)
    {
        if (friends[i].yday == yday)
        {
            if ((friends[i].day == timeToday->tm_mday) && (friends[i].month == timeToday->tm_mon))
                std::cout << "Today birthday of " << friends[i].name << "\n";
            else 
                std::cout << "Nearest birtday of " << friends[i].name << " ,days left " << minDay << "\n";
        }
    }
}
