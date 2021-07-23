#include <iostream>


int main() {
    int array[] = {-200, -150, -100, -50, -5, 1, 10, 15, 20};
    int i = 0;
    int size = sizeof(array)/4;
    for (; array[i] < 0; ++i )
    {
    }
    for (int j=i-1; i < size  or j >= 0;) 
    {
        if (array[i] < (array[j]*(-1)) and i!=size)
        {
            std::cout << array[i] << " ";
            ++i;
        }
        else 
        {
            std::cout << array[j] << " ";
            --j;
        }
    }
    std::cout << "\n";
}
