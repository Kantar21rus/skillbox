#include <iostream>

int func(int a)
{
    int sum=0;
    if (a>=3)
    {
        sum+=func(a-3);
        ++sum;
    }   
    if (a>=2)
    {
        sum+=func(a-2);
        ++sum;
    }
    if (a>=1)
    {
        sum+=func(a-1);
    }
    return sum;
}

int main() 
{
    int input;
    std::cout << "Input: ";
    std::cin >> input;
    std::cout << "Output: " << func(input)+1 << "\n";
}
