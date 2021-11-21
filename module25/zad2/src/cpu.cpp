#pragma once
#include "gpu.h"


int sum(int ram[])
{
    int summa = 0;
    for (int i=0; i < 8; ++i)
        summa += ram[i];
    display(&summa, 1);
    return summa;
}
