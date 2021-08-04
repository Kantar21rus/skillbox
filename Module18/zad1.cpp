#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int (&array)[4])
{
    int temp;
    for (int i=0; i < 4; ++i)
    {
        temp = vec[i];
        vec[i] = array[i];
        array[i] = temp;
    }
}

int main ()
{
    std::vector<int> a={1,2,3,4};
    int b[]={2,4,6,8};
    swapvec(a, b);
    for (int i=0; i<4; ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
    for (int i=0; i<4; ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";
}
