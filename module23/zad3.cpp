#include <iostream>

#define SPRING 1
#define SUMMER 0
#define AUTUMN 1
#define WINTER 0


int main()
{

#if SPRING
    std::cout << "SPRING\n";
#endif
#if SUMMER
    std::cout << "SUMMER\n";
#endif
#if AUTUMN
    std::cout << "AUTUMN\n";
#endif
#if WINTER
    std::cout << "WINTER\n";
#endif

}
