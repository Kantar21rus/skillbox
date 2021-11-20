#include <iostream>
#include "mylib.h"

struct cut
{
    point start;
    point finish;
    bool open = false;
};

int main()
{
    cut ourCut;
    std::cout << "Insert coordinats, Start point: ";
    std::cin >> ourCut.start.corX >> ourCut.start.corY;
    std::cout << "Finish point: ";
    std::cin >> ourCut.finish.corX >> ourCut.finish.corY;
    scalpel(ourCut.start, ourCut.finish);
    ourCut.open = true;
    for (;ourCut.open;)
    {
        std::string comand = "";
        std::cout << "Insert command: ";
        std::cin >> comand;
        if (comand == "scalpel")
        {
            point startPoint, finishPoint;
            std::cout << "Insert coordinats, Start point: ";
            std::cin >> startPoint.corX >> startPoint.corY;
            std::cout << "Finish point: ";
            std::cin >> finishPoint.corX >> finishPoint.corY;
            scalpel(startPoint, finishPoint);
        }
        else if (comand == "hemostat")
        {
            point startPoint;
            std::cout << "Insert coordinats, point: ";
            std::cin >> startPoint.corX >> startPoint.corY;
            hemostat(startPoint);
        }
        else if (comand == "tweezers")
        {
            point startPoint;
            std::cout << "Insert coordinats, point: ";
            std::cin >> startPoint.corX >> startPoint.corY;
            tweezers(startPoint);
        }
        else if (comand == "suture")
        {
            point startPoint, finishPoint;
            std::cout << "Insert coordinats, Start point: ";
            std::cin >> startPoint.corX >> startPoint.corY;
            std::cout << "Finish point: ";
            std::cin >> finishPoint.corX >> finishPoint.corY;
            suture(startPoint, finishPoint);
            if (startPoint.corX == ourCut.start.corX && startPoint.corY == ourCut.start.corY &&
                    finishPoint.corX == ourCut.finish.corX && finishPoint.corY == ourCut.finish.corY)
            {
                ourCut.open = false;                
            }
            else 
            {
                std::cout << "Not full sew up or wrong\n";
            }
        }
    }
    std::cout << "Operation is done\n";
}
