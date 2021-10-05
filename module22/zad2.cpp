#include <iostream>
#include <map>
#include <string>

int main()
{
    bool run = true;
    std::string input;

    std::map<std::string, std::string> registry;
    for (int i=0; run ; ++i )
    {
        std::cin >> input;
        if (input == "Next")
        {
            std::cout  << registry.begin()->second << "\n";
            registry.erase(registry.begin()->first);
        }
        else 
        {
            registry.insert(std::pair<std::string, std::string>(input + (char) i, input));

        }
    }
}
