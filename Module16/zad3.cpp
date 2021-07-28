#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>


int main() {
    double number1;
    double number2;
    char oper;
    char nums1[50];
    char nums2[50];
    char input[100];
    scanf("%s", &input);
    int i = 0;
    int j = 0;
    int k = 0;
    bool firstNumber = true;
    bool secondNumber = false;
    for(; input[i] != 0; ++i) 
    {
        if (input[i] == '*' or input[i] == '/' or input[i] == '+' or input[i] == '-') 
        {
            oper = input[i];
            firstNumber = false;
            secondNumber = true;
        }
        else if (firstNumber) 
        {
            nums1[i] = input[i];
            j = i;
        }
        else if (secondNumber)
        {
            nums2[k] = input[i];
            ++k;
        }
    }
    nums1[j+1] = '\0';
    nums2[k] = '\0';
    number1 = atof(nums1);
    number2 = atof(nums2);
    switch (oper)
    {
        case '+':
            std::cout << number1+number2 << "\n";
            break;
        case '-':
            std::cout << number1-number2 << "\n";
            break;
        case '*':
            std::cout << number1*number2 << "\n";
            break;
        case '/':
            std::cout << number1/number2 << "\n";
            break;
    }
}
