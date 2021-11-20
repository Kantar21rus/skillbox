#pragma once
#include <iostream>


struct point
{
    double corX;
    double corY;
};


void scalpel(point start, point finish)
{
    std::cout << "You made the cut between (" << start.corX << " . " << start.corY << ") and (" << finish.corX << " . " << finish.corY << ")\n";
}

void hemostat(point start)
{
    std::cout << "You do clip (" << start.corX << " . " << start.corY << ")\n";
}

void tweezers(point start)
{
    std::cout << "You use tweezers (" << start.corX << " . " << start.corY << ")\n";
}

void suture(point start, point finish)
{
    std::cout << "You sew up the skin between (" << start.corX << " . " << start.corY << ") and (" << finish.corX << " . " << finish.corY << ")\n";
}
