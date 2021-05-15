#include <iostream>

int main() {
  bool tiny[1];
  bool small[2];
  bool middle[3];
  bool big[4];

  std::cout << "Tiny:\t" << sizeof(tiny) << "\n";
  std::cout << "Small:\t" << sizeof(small) << "\n";
  std::cout << "Middle:\t" << sizeof(middle) << "\n";
  std::cout << "Big:\t" << sizeof(big) << "\n";
}
