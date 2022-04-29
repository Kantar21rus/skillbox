#include <iostream>
#include <string>

enum {
    sizeArray = 5
};

template <typename T>
void input(T array[sizeArray]) {
    std::cout << "Fill the array ("<< sizeArray << "):";
    for (int i=0; i < sizeArray; ++i) {
        std::cin >> array[i];
    }
}

template <typename T>
T arithmeticMean(T array[sizeArray]) {
    T average;
    T sum = 0;
    for (int i=0; i < sizeArray; ++i) {
        sum += array[i];
    }
    average = sum / sizeArray;
    std::cout << "average "<<average << "\n";
    return average;
}

int main() {
    std::string command = "";
    std::cout << "Insert array type: ";
    std::cin >> command;
    if (command == "int") {
        int array[sizeArray];
        int average = 0;
        input(array);
        average = arithmeticMean(array);
        std::cout << "average "<<average << "\n";
    } else if (command == "float") {
        float array[sizeArray];
        float average = 0;
        input(array);
        average = arithmeticMean(array);
        std::cout << "average "<<average << "\n";
    } else if (command == "double") {
        double array[sizeArray];
        double average = 0;
        input(array);
        average = arithmeticMean(array);
        std::cout << "average "<<average << "\n";
    } 
}
