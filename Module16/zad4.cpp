#include <iostream>



enum notes {countComb = 12};

int main() {
    std::string buf = "";
    for (int i=0; i< countComb; ++i) 
    {
        std::string input;
        std::cout << "Input " << i+1 << " combination:\n";
        std::cin >> input;
        if (input.length() != 3) 
        {
            input = "";
            --i;
            std::cout << "Wrong length combination!\n";
        }
        else if (!(input[0] >= '1' and input[0] <= '7' and 
                    input[1] >= '1' and input[1] <= '7' and 
                    input[2] >= '1' and input[2] <= '7')) 
        {
            input = "";
            --i;
            std::cout << "Wrong notes!\n";
        }
        else 
        {
            buf += input;
        }
    }
    for (int i=0; i < 3*countComb; ++i) 
    {
        switch (buf[i])
        {
            case '1':
                std::cout << "Do ";
                break;
            case '2':
                std::cout << "Re ";
                break;
            case '3':
                std::cout << "Mi ";
                break;
            case '4':
                std::cout << "Fa ";
                break;
            case '5':
                std::cout << "Sol ";
                break;
            case '6':
                std::cout << "La ";
                break;
            case '7':
                std::cout << "Si ";
                break;
        }
    } 
    std::cout << "\n";
}
