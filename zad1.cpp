#include <iostream>

int main() {
  bool tiny[1];
  bool small[2];
  bool middle[3];
  bool big[4];

  std::cout << "Tiny:\t" << sizeof(tiny)/sizeof(bool)  << "\n";
  std::cout << "Small:\t" << sizeof(small)/sizeof(bool) << "\n";
  std::cout << "Middle:\t" << sizeof(middle)/sizeof(bool) << "\n";
  std::cout << "Big:\t" << sizeof(big)/sizeof(bool) << "\n";
}
