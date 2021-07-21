#include <iostream>




int main() {
    int a[] = {2, 7, 11, 15};
    int result;

    std::cout << "Insert result number: ";
    std::cin >> result;
    for (int i = 0; i < (sizeof(a)/sizeof(int)-1); ++i ) {
        for (int j = i + 1; j < (sizeof(a)/sizeof(int)); ++j) {
            if(result == a[i] + a[j]) {
                std::cout << "Numbers: " << a[i] << " and " << a[j] << "\n";
                return 0;
            }
        }
    }
    std::cout << "Haven't numbers, for this result!\n";
    return 1;
}
