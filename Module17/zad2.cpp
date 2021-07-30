#include <iostream>

void func(int* array)
{
    int j=9;
    for(int i=0; i<j; ++i,--j)
    {
        int temp = *(array+i);
        *(array+i)=*(array+j);
        *(array+j)= temp;
    }
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func(array);
    for(int i=0; i<10; ++i)
        std::cout << *(array+i) << " ";
    std::cout << "\n";
}
