#include <iostream>
#include <vector>


int main() {
  int n, x;
  int countX = 0;
  std::cin >> n;
  std::cout << "------------------------\n";
  std::vector<int> vec1(n);
  std::vector<int> vec2(0);
  for (int i=0; i < n ;++i) {
    std::cin >> vec1[i];
  }
  std::cout << "------------------------\n";
  std::cin >> x;
  std::cout << "------------------------\n";
  for (int i=0; i < n ; ++i) {
    if (vec1[i] == x) {
      ++countX;
    } else {
      vec2.push_back(vec1[i]);
    }
  }
  
  for (int i=0; i < (n-countX) ;++i) {
    std::cout << vec2[i] << "\t";
  }
  std::cout << "\n";
  
  return 0;
}  
