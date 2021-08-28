#include <iostream>
#include <fstream>

bool itsPNG1 (char buffer[4])
{
    if (buffer[0]== -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
        return true;
    return false;
}

bool itsPNG2 (std::string dir)
{
    int i = dir.length();
    for (int n=0; n < (i-3); ++n)
    {
        if ( dir[n] == '.' && dir[n+1] == 'p' && dir[n+2] == 'n' && dir[n+3] == 'g')
            return true;
    }
    return false;
}

int main()
{
    char buffer[4];
    std::string directory;
    std::cout << "Insert directory: ";
    std::cin >> directory;
    std::ifstream file;
    file.open(directory, std::ios::binary);
    if (file.is_open())
    {
        file.read(buffer, sizeof(buffer));
        if (itsPNG1(buffer) && itsPNG2(directory))
        {
            file.close();
            std::cout << "It's PNG file\n";
            return 0;
        }
        std::cout << "It's NOT PNG file\n";
        file.close();
        return 1;
    } 
    else
        std::cout << "File not open\n";
    return 1;
}
