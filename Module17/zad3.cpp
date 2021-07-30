#include <iostream>
#include <cstring>

bool substr (char* full, char* part, int size) 
{
    for (int i=0; *(full+i); ++i)
    {
        if ((*(full+i)) == (*part))
        {
            int count=0;
            for(int j=0;*(part+j); ++j)
            {
                if (*(full+i+j)==*(part+j))
                    ++count;
            }
            if (count == size)
                return true;
        }
    }
    return false;
}

int main() {
    char* a= "Hello world";
    char* b= "ld";
    char* c= "olo";
    std::cout<< (substr(a, b, strlen(b))? "true" : "false") << " " 
        << (substr(a, c, strlen(c))? "true" : "false") << "\n";
}
