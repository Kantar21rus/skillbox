#include <iostream>
#include <string>
#include <map>


int main()
{
    std::string insert;
    bool run = true;

    std::map<std::string, std::string> oMap;
    oMap.insert(std::make_pair<std::string, std::string> ("69-70-30", "Ivanov"));
    oMap.insert(std::make_pair<std::string, std::string> ("69-80-30", "Petrov"));
    oMap.insert(std::make_pair<std::string, std::string> ("69-60-30", "Reznov"));
    oMap.insert(std::make_pair<std::string, std::string> ("69-50-30", "Petrov"));
    while (run)
    {
    std::getline(std::cin, insert);
        if ((insert[0] >= 'A' && insert[0] <= 'Z') || (insert[0] >= 'a' && insert[0] <= 'z'))
        {
            for ( std::map<std::string, std::string>::iterator itr = oMap.begin(); itr != oMap.end(); ++itr)
            {    
                if (insert == itr->second)
                {
                    std::cout << itr->first << " ";
                } 
            }
            std::cout << "\n";
        }
        else if ((insert[0] >= '0' && insert[0] <= '9') && insert.length() > 9)
        {
            std::string firstPart;
            std::string secondPart;
            firstPart = insert.substr(0, 8);
            secondPart = insert.substr(9, (insert.length()-9));
            oMap.insert(std::pair<std::string, std::string> (firstPart, secondPart));
        }
        else if (insert[0] >= '0' && insert[0] <= '9')
        {
            std::map<std::string, std::string>::iterator itr = oMap.find(insert);
            std::cout << itr->second << "\n";
        }
    }
}
