#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string name;
    std::string surename;
    std::string date;
    int sum;
    bool quit = false;
    std::ofstream file;
    file.open("list.txt", std::ios::app);
    std::cout << "If you wan't quit, enter \"quit\" in name\n";
    while (!quit)
    {
        std::cout << "Enter Name, Surname, date DD.MM.YYYY format and money:\n";
        std::cin >> name ;
        if ( name == "quit")
        {
            quit = true;
        }
        else
        {
            std::cin >> surename >> date >> sum;
            int dateD = std::stoi(date.substr(0, 2));
            int dateM = std::stoi(date.substr(3, 2));
            int dateY = std::stoi(date.substr(6, 4));
            if (!((dateD > 0 && dateD < 32) && (dateM > 0 && dateM < 13) && (dateY >= 1900 && dateY <= 2021))) 
            {
                std::cout << "Invalid Date!\n";
                continue;
            }
            if ( sum <= 0)
            {
                std::cout << "Wrong money\n";
                continue;
            }
            file << name << " " << surename << " " << date << " " << sum << " RUB\n";
            std::cout << "Successfully write!\n";
        }
    }
    file.close();
}
