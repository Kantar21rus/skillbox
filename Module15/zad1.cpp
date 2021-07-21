#include <iostream>

int sum(int *start, int size) {
    int eax = 0;
    for (int i = 0; i < size; ++i)
    {
        eax += *(start+i);
    }
    return eax;
}


int main() {
    int array[] = {-2, 1, -3,  4, -1, 2, 1, -5, 4};
    int summa = 0;
    int maxsum = 0;
    int bi, bj;
    for (int i=0; i < (sizeof(array)/4); ++i) {
        for (int j=(sizeof(array)/4); j > i; --j) 
        {
            summa = sum(&array[i], j-i);    
            if (maxsum < summa)
            {
                maxsum = summa;
                bi = i;
                bj = j-1;
            }
        }
    }

    std::cout << "Start index " << bi << " , Finish index " << bj  << "\n";
    

    return 0;
}
