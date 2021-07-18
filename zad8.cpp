#include <iostream>

int main() {
  int field[5][5][10];
  int input;
  int output;
  std::cout << "Input blocks height:\n";
  for (int i=0; i < 5; ++i) {
    for (int j=0; j < 5; ++j) {
      std::cin >> input;
      for (int k=0; k < 10; ++k) {
	if (k<=input) {
	  field[i][j][k] = 1;
	} else {
	field[i][j][k] = 0;
	}
      }
    }
  }
  std::cout << "input watch level\n";
  std::cin >> output;
  for (int i=0; i < 5; ++i) {
    for (int j=0; j < 5; ++j) {
      std::cout << field[i][j][output] << " ";
    }
    std::cout << "\n";
  }
}
  
