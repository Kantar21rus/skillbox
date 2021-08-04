#include <iostream>

int func(int a, int k=3)
{
    int sum=0;
    for (int i=k; i>1; --i)
    {
        if(a>=i)
        {
            sum+=func(a-i, k);
            ++sum;
        }
    } 
    if (a>=1)
    {
        sum+=func(a-1, k);
    }
    return sum;
}

int main() 
{
    int input, k;
    std::cout << "Input: ";
    std::cin >> input ;
    std::cin >> k;
    std::cout << "Output: " << func(input, k)+1 << "\n";
}
