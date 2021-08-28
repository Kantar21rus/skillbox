#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::string word;
    std::string inpWord;
    int count = 0;
    std::ifstream input;
    input.open("words.txt");
    std::cout << "Which word search: ";
    std::cin >> inpWord;
    while (!input.eof())
    {
        word = "";
        input >> word;
        if (word == inpWord)
            ++count;
    }
    input.close();
    std::cout << "Count " << inpWord << ": " << count << "\n";
}
