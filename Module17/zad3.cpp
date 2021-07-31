#include <iostream>
#include <cstring>

bool substr (char* full, char* part) 
{
    for (int i=0; *(full+i); ++i)
    {
        if ((*(full+i)) == (*part))
        {
            for(int j=0;*(part+j); ++j)
            {
                if ((*(full+i+j)==*(part+j)) and *(part+j+1)=='\0')
                    return true;
            }
        }
    }
    return false;
}

int main() {
    char* a= "Hello world";
    char* b= "Hel";
    char* c= "o ww";
    std::cout<< (substr(a, b)? "true" : "false") << " " 
        << (substr(a, c)? "true" : "false") << "\n";
}
