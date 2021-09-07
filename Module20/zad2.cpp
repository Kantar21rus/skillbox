#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    int height;
    int width;
    bool cursor;
    std::cout << "Input height and width: ";
    std::cin >> height >> width;
    std::srand(std::time(nullptr));
    std::ofstream file;
    file.open("pic.txt");
    for (int i = 0; i < height; ++i)
    {
        for (int n = 0; n < width; ++n)
        {
            cursor = std::rand() % 2;
            file << cursor;
        }
        file << "\n";
    }
    file.close();
}

