#include <iostream>
#include <vector>
#include <string>

enum {
    integerType = 0,
    doubleType = 1,
    stringType = 2,
};

template<typename K, typename V>
struct RegistryPair {
    K key;
    V value;

    RegistryPair(K k, V v): key(k), value(v) {}
};

class AllReg {
    public:
        virtual void print() const = 0;
};

template<typename K, typename V>
class Registry: public AllReg {
    std::vector<RegistryPair<K, V> > elements;

    public:

    void add(K key, V value) {
        RegistryPair<K, V> tmp(key, value);
        elements.push_back(tmp);
    }

    bool remove(K key) {
        if (!elements.empty()) {
            auto iter = elements.begin();
            while (iter->key != key) {
                ++iter;
                if (iter == elements.end()) {
                    return false;
                }
            }
            elements.erase(iter);
            while (this->remove(key)) {
            }
            return true;
        } else {
            return false;
        }
    }

    void print() const {
        for(auto iter = elements.begin(); iter != elements.end(); ++iter) {
            std::cout << iter->key << " " << iter->value << "\n";
        }
    }

    int find(K key) const {
        int returnCount = 0;
        for(auto iter = elements.begin(); iter != elements.end(); ++iter) {
            if ( key == iter->key) {
                std::cout << iter->value << "\n";
                ++returnCount;
            }
        }
        return returnCount;
    }
};

void ParcingType(std::string input, int& intType, double& dbType, std::string& strType, int& returnType) {
    bool onlyDigits = true;
    bool haveDot = false;

    for (int i=0; i < input.length(); ++i) {
        if ((input[i] < '0' || input[i] > '9') && input[i] != '.') {
            onlyDigits = false;
        }
        if (input[i] == '.') {
            haveDot = true;
        }
    }
    if (onlyDigits and !haveDot) {
        intType = std::stoi(input);
        returnType = integerType;
    } else if (onlyDigits and haveDot) {
        dbType = std::stod(input);
        returnType = doubleType;
    } else if (!onlyDigits) {
        strType = input;
        returnType = stringType;
    }
}

int main() {
    AllReg* allReg[9];
    Registry<int, int> RII;
    Registry<int, double> RID;
    Registry<int, std::string> RIS;
    Registry<double, int> RDI;
    Registry<double, double> RDD;
    Registry<double, std::string> RDS;
    Registry<std::string, int> RSI;
    Registry<std::string, double> RSD;
    Registry<std::string, std::string> RSS;
    allReg[0] = &RII;
    allReg[1] = &RID;
    allReg[2] = &RIS;
    allReg[3] = &RDI;
    allReg[4] = &RDD;
    allReg[5] = &RDS;
    allReg[6] = &RSI;
    allReg[7] = &RSD;
    allReg[8] = &RSS;
    
    int returnType = 0; 
    int inpI = 0;
    double inpD = 0;
    std::string inpS = "";
    for (;;) {
        std::string comand = "";
        std::cout << "insert comand: ";
        std::cin >> comand;
        if (comand == "add") {
            std::cout << "insert key: ";
            std::string input = "";
            std::cin >> input;
            ParcingType(input, inpI, inpD, inpS, returnType);
            if (returnType == integerType) {
                int key = inpI;
                inpI = 0;
                inpD = 0;
                inpS = "";
                std::cout << "insert value: ";
                input = "";
                std::cin >> input;
                ParcingType(input, inpI, inpD, inpS, returnType);
                if (returnType == integerType) {
                    int value = inpI;
                    RII.add(key, value);
                } else if (returnType == doubleType) {
                    double value = inpD;
                    RID.add(key, value);
                } else if (returnType == stringType) {
                    std::string value = inpS;
                    RIS.add(key, value);
                }
            } else if (returnType == doubleType) {
                double key = inpD;
                inpI = 0;
                inpD = 0;
                inpS = "";
                std::cout << "insert value: ";
                input = "";
                std::cin >> input;
                ParcingType(input, inpI, inpD, inpS, returnType);
                if (returnType == integerType) {
                    int value = inpI;
                    RDI.add(key, value);
                } else if (returnType == doubleType) {
                    double value = inpD;
                    RDD.add(key, value);
                } else if (returnType == stringType) {
                    std::string value = inpS;
                    RDS.add(key, value);
                }
            } else if (returnType == stringType) {
                std::string key = inpS;
                inpI = 0;
                inpD = 0;
                inpS = "";
                std::cout << "insert value: ";
                input = "";
                std::cin >> input;
                ParcingType(input, inpI, inpD, inpS, returnType);
                if (returnType == integerType) {
                    int value = inpI;
                    RSI.add(key, value);
                } else if (returnType == doubleType) {
                    double value = inpD;
                    RSD.add(key, value);
                } else if (returnType == stringType) {
                    std::string value = inpS;
                    RSS.add(key, value);
                }
            }
            
        } else if (comand == "remove") {
            std::string input = "";
            std::cout << "Enter key for remove: ";
            std::cin >> input;
            inpI = 0;
            inpD = 0;
            inpS = "";
            ParcingType(input, inpI, inpD, inpS, returnType);
            if (returnType == integerType) {
                int key = inpI;
                RII.remove(key);
                RID.remove(key);
                RIS.remove(key);
            } else if (returnType == doubleType) {
                double key = inpD;
                RDI.remove(key);
                RDD.remove(key);
                RDS.remove(key);
            } else if (returnType == stringType) {
                std::string key = inpS;
                RSI.remove(key);
                RSD.remove(key);
                RSS.remove(key);
            }
        } else if (comand == "print") {
            for (int i=0; i < 9; ++i) {
                allReg[i]->print();
                std::cout << "------\n";
            }
        } else if (comand == "find" ) {
            int findSomething = 0;
            std::string input = "";
            std::cout << "Enter the search key: ";
            std::cin >> input;
            inpI = 0;
            inpD = 0;
            inpS = "";
            ParcingType(input, inpI, inpD, inpS, returnType);
            if (returnType == integerType) {
                int key = inpI;
                findSomething += RII.find(key);
                findSomething += RID.find(key);
                findSomething += RIS.find(key);
            } else if (returnType == doubleType) {
                double key = inpD;
                findSomething += RDI.find(key);
                findSomething += RDD.find(key);
                findSomething += RDS.find(key);
            } else if (returnType == stringType) {
                std::string key = inpS;
                findSomething += RSI.find(key);
                findSomething += RSD.find(key);
                findSomething += RSS.find(key);
            }
            if (!findSomething) {
                std::cout << "This key not found!\n";
            }
        } else if (comand == "exit") {
            return 0;
        } else {
            std::cout << "invalid comand\n";
        }
    }
}
