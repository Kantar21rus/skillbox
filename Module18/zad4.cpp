#include <iostream>

void func(long long num,int& output)
{
    if((num%10)%2==0)
       ++output;
    if (num >= 10)
        func(num/10, output);
}

int main()
{
    long long input;
    int output=0;
    std::cin >> input;
    func(input, output);
    std::cout << output << "\n";
}

