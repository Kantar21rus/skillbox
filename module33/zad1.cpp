#include <iostream>
#include <exception>
#include <map>
#include <stdexcept>
#include <string>

int main() {
    std::map<std::string, int> storage;
    for (bool notFill = true; notFill ;) {
        std::string inputName = "";
        int count = 0;
        std::cout << "insert goods name or if you finished enter 'fill': ";
        std::cin >> inputName;
        if (inputName == "fill") {
            notFill = false;
            break;
        }
        std::cout << "insert goods count: ";
        std::cin >> count;
        std::pair<std::string, int> tmpPair { inputName, count};
        storage.insert(tmpPair);
    }
    for(auto iter = storage.begin();iter != storage.end(); ++iter) {
        std::cout << iter->first << " - " << iter->second << "\n";
    }

    std::cout << "you enter shopping basket\n";
    std::map<std::string, int> basket;
    for (;;) {
        std::string comand = "";
        std::string name = "";
        int count = 0;
        std::cout << "insert comand: ";
        std::cin >> comand;
        if (comand == "add") {
            try {
                std::cout << "insert name and count: ";
                std::cin >> name >> count;
                auto findName = storage.find(name);
                if (findName == storage.end()) {
                    throw std::invalid_argument("this goods absent in storage");
                } else {
                    try {
                       if (findName->second < count) {
                           throw std::invalid_argument("there is no such quantity in stock");
                       } else {
                           std::pair<std::string, int> tmpPair { name, count};
                           basket.insert(tmpPair);
                       }
                    } catch (const std::invalid_argument) {
                        std::cerr << "Caught exception: "<< name << " this product is not in quantity " << count << "\n";
                    }
                }
            } catch (const std::invalid_argument) {
                std::cerr << "Caught exception: haven't this good in storage " << name << "\n";
            }
        } else if (comand == "remove") {
            if (basket.empty()) {
                std::cout << "basket empty, you can't remove goods\n";
            } else {
                try {
                    std::cout << "insert name and count: ";
                    std::cin >> name >> count;
                    auto findName = basket.find(name);
                    if (findName == basket.end()) {
                        throw std::invalid_argument("this goods absent in basket");
                    } else {
                        try {
                            if (findName->second < count) {
                                throw std::invalid_argument("there is no such quantity in stock");
                            } else if (findName->second == count){
                                basket.erase(findName);
                            } else {
                                findName->second -= count;
                            }
                        } catch (const std::invalid_argument) {
                            std::cerr << "Caught exception: you can't remove "<< name << " from basket, because count good in basket less then " << count << "\n";
                        }
                    }
                } catch (const std::invalid_argument) {
                    std::cerr << "Caught exception: haven't this good in storage " << name << "\n";
                }
            }
        } else if (comand == "show") {
            if (basket.empty()) {
                std::cout << "basket empty\n";
            } else {
                for(auto iter = basket.begin();iter != basket.end(); ++iter) {
                    std::cout << iter->first << " - " << iter->second << "\n";
                }
            }
        } else if (comand == "close") {
            break;
        }
    }
}
