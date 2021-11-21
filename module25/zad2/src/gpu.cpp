#pragma once
#include <iostream>

void display(int *num, int count)
{
    for (int i=0; i < count; ++i)
    {
        std::cout << *(num+i) << " ";
    }
    std::cout << "\n";
}
