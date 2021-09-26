#include <iostream>
#include <fstream>
#include <string>


struct list
{
    std::string name;
    std::string surename;
    std::string date;
    int sum;
    std::string currency;
};

int main()
{
    list person;
    std::string mode;
    std::cout << "If you want to look at the list, enter \"list\"\nIf you want add new  person, enter \"add\"\n";
    std::cin >> mode;
    if (mode == "add")
    {
        std::ofstream file;
        file.open("list.txt", std::ios::app);
        std::cout << "Enter Name, Surname, date DD.MM.YYYY format, money quantity and currancy:\n";
        std::cin >> person.name ;
        std::cin >> person.surename >> person.date >> person.sum >> person.currency;
        int dateD = std::stoi(person.date.substr(0, 2));
        int dateM = std::stoi(person.date.substr(3, 2));
        int dateY = std::stoi(person.date.substr(6, 4));
        if (!((dateD > 0 && dateD < 32) && (dateM > 0 && dateM < 13) && (dateY >= 1900 && dateY <= 2021))) 
        {
            std::cout << "Invalid Date!\n";
        }
        if ( person.sum <= 0)
        {
            std::cout << "Wrong money\n";
        }
        file << person.name << " " << person.surename << " " << person.date << " " << person.sum << " " << person.currency << "\n";
        std::cout << "Successfully write!\n";
        file.close();
    }
    else if (mode == "list")
    {
        std::ifstream file;
        file.open("list.txt");
        while (!file.eof())
        {
            person.name = "";
            file >> person.name;
            if (person.name == "")
                return 0;
            file  >> person.surename >> person.date >> person.sum >> person.currency;
            std::cout << person.name << " " << person.surename << " " << person.date << " " << person.sum << " " << person.currency<< "\n";
        }
        file.close();
    }
}
