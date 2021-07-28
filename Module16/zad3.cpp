#include <iostream>
#include <vector>


int main() {
    std::vector<int> vec(0);
    int input = 0;
    for(;;) {
        std::cout << "Insert: ";
        std::cin >> input;
        if ( input == -1 ) { 
            if (vec.size()< 5) {
                std::cout << "to small array!\n";
            } else {
               std::cout << "Output: " << vec[4] << "\n";
               std::cout << "Vector:";
               for (int i=0; i < vec.size(); ++i) {
                   std::cout << " " << vec[i];
               }
               std::cout << "\n";
            }

        } else if ( input == -2) {
            return 0;
        } else {
            vec.insert(vec.begin(), input);
            for (int i=0; i < vec.size(); ++i) {
                for (int j=0; j < vec.size()-i-1; ++j) {
                    if (vec[j] > vec[j+1]) {
                        int tmp = vec[j];
                        vec[j] = vec[j+1];
                        vec[j+1] = tmp;
                    }
                }
            }
        }
    }
}
