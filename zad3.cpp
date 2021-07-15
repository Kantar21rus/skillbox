#include <iostream>
#include <vector>

int main() {
  std::vector<int> data(20);
  for (;;) {
    int input;
    std::cin >> input;
    if (input == -1) {
      std::cout << "---------------\n";
      for(int i = 0; i < 20 ; ++i) {
	std::cout << data[i] << "\t";
      }
      std::cout << "\n";
      return 0;
    }
    for(int i=0; i < 19; ++i ) {
      data[i] = data[i+1];
    }
    data[19] = input;
  }
}
    
