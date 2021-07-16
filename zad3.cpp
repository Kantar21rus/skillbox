#include <iostream>
#include <vector>

int main() {
  std::vector<int> data(20);
  int pos = 0;
  for (;;) {
    int input;
    std::cin >> input;
    if (input == -1) {
      std::cout << "---------------\n";
      for(int i = pos; i < data.size() ; ++i) {
	std::cout << data[i] << "\t";
      }
      for(int i = 0; i < pos ; ++i) {
	std::cout << data[i] << "\t";
      }
      std::cout << "\n";
      return 0;
    }
    data[pos] = input;
    ++pos;
    if (pos == 20) {
      pos =0;
    }
  }
}
    
