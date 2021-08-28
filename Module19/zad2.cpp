#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    char buffer1[10];
    std::string directory;
    std::cout << "Insert directory: ";
    std::cin >> directory;
    std::ifstream file;
    file.open(directory, std::ios::binary);
    std::stringstream output;
    if (file.is_open())
    {
        while(!file.eof())
        {
            file.read(buffer1, sizeof(buffer1));
            /*for (int i=0; i < 10; ++i)
            {
                buffer2[i] = buffer1[i];
                if (buffer1[i]==0)
                    break;
            }*/
            for (int i=0; i<10 and buffer1[i]!='\0'; ++i)
            {
                //std::cout << buffer1[i];
                if (buffer1[i] != EOF)
                {
                    output << buffer1[i];
                }
                else if (buffer1[i] == EOF)
                {
                    output << '\n' << '\0';
                    break;
                }
                buffer1[i] = '\0';
            }
        }
        file.close();
        std::cout << output.str();
    } 
    else
        std::cout << "File not open\n";
    std::cout << "\n";
}
