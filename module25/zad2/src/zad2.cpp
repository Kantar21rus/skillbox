#include <iostream>
#include "cpu.h"
#include "gpu.h"
#include "ram.h"
#include "disk.h"
#include "kbd.h"

int main()
{
    std::string comand = "";
    int ram[8];
    for (int i=0; i < 8; ++i)
        ram[i] = 0;
    for (;comand != "exit";)
    {
        std::cin >> comand;
        if (comand == "exit")
            return 0;
        else if (comand == "sum")
            sum(ram);
        else if (comand == "display")
            display(ram, 8);
        else if (comand == "input")
            input(ram);
        else if (comand == "save")
            save(ram);
        else if (comand == "load")
            load(ram);

    }
}
