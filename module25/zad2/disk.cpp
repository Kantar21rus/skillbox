#pragma once
#include "disk.h"
#include <fstream>

void save(int *buf)
{
    std::ofstream file;
    file.open("data.txt");
    for (int i=0; i<8; ++i)
    {
        file << *(buf+i) << " ";
    }
    file.close();
}

void load(int *buf)
{
    std::ifstream file;
    file.open("data.txt");
    for (int i=0; i<8; ++i)
    {
        file >> *(buf+i);
    }
    file.close();
}
