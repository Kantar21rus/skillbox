#include <iostream>
#include <fstream>

int main()
{
    int count = 0;
    bool exit = false;
    std::string quit = "quit";
    std::string inFish;
    std::string findFish;
    std::ifstream input;
    std::ofstream output;
    output.open("basket.txt", std::ios::app);
    std::cout << "If you want exit from fishing, enter \"quit\" in fish you want!\n";
    while (!exit)
    {
        std::cout << "Whitch fish you want: ";
        std::cin >> findFish;
        input.open("river.txt");
        if (findFish == quit)
        {
            exit = true;
            continue;
        }
        while (!input.eof())
        {
            input >> inFish;
            if (findFish == inFish)
            {
                output << inFish << "\n";
                ++count;
            }
            inFish = "";
        }
        input.close();
    }
    output.close();
    std::cout << "You catch " << count << " fish\n";
}

