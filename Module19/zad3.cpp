#include <iostream>
#include <fstream>


int main()
{
    int sum=0;
    std::string name;
    std::string surname;
    std::string maxName;
    std::string maxSurname;
    int money;
    int maxMoney = 0;
    std::string maxDate;
    std::string date;
    std::ifstream file;
    file.open("list.txt");
    while (!file.eof())
    {
        file >> name >> surname >> money >> date;
        if (money > maxMoney)
        {
            maxMoney = money;
            maxName = name;
            maxSurname = surname;
            maxDate = date;
        }
        sum += money;
        money = 0;
    }
    file.close();
    std::cout << "Money from all users: " << sum << "\n" << maxName << " " << maxSurname << " " << maxMoney << " " << maxDate << "\n";

}
