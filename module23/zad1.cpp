#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define DAY_MONDAY "MONDAY" 
#define DAY_TUESDAY "TUESDAY"
#define DAY_WEDNESDAY "WEDNESDAY"
#define DAY_THURSDAY "THURSDAY"
#define DAY_FRIDAY "FRIDAY"
#define DAY_SATURDAY "SATURDAY"
#define DAY_SUNDAY "SUNDAY"

#define FUNC(a,b) a ##_## b

int main()
{
    int input;
    std::cin >> input;
    switch (input) 
    {
        case MONDAY:
            {
                std::cout  << FUNC(DAY, MONDAY) << "\n";
                break;
            }
        case TUESDAY:
            {
                std::cout  << FUNC(DAY, TUESDAY) << "\n";
                break;
            }
        case WEDNESDAY:
            {
                std::cout  << FUNC(DAY, WEDNESDAY) << "\n";
                break;
            }
        case THURSDAY:
            {
                std::cout  << FUNC(DAY, THURSDAY) << "\n";
                break;
            }
        case FRIDAY:
            {
                std::cout  << FUNC(DAY, FRIDAY) << "\n";
                break;
            }
        case SATURDAY:
            {
                std::cout  << FUNC(DAY, SATURDAY) << "\n";
                break;
            }
        case SUNDAY:
            {
                std::cout  << FUNC(DAY, SUNDAY) << "\n";
                break;
            }

    }
}
