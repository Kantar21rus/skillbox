#include <iostream>
#include <cmath>


int main() {
    int array[] = {-100, -50, -5, 1, 10, 15};
    for (int i=0; i < sizeof(array)/sizeof(int); ++i) {
        for (int j=0; j < sizeof(array)/sizeof(int) - i - 1; ++j) {
            if ( std::abs(array[j]) > std::abs(array[j+1])) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < sizeof(array)/sizeof(int); ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
    std::cout << "\n";
}
