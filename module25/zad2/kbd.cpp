#pragma once
#include <iostream>
#include "ram.h"

void input( int *rambuf)
{
    int kbuf[8];
    for (int i=0; i<8; ++i)
        std::cin >> kbuf[i];
    write(rambuf, kbuf);
}
