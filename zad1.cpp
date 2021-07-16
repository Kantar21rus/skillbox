#include <iostream>
#include <vector>


int main() {
  int n, x;
  int countX = 0;
  std::cin >> n;
  std::cout << "------------------------\n";
  std::vector<int> vec1(n);
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
      vec1[i-countX]=vec1[i];
    }
  }
  vec1.resize(n-countX);
  for (int i=0; i < (n-countX) ;++i) {
    std::cout << vec1[i] << "\t";
  }
  std::cout <<"\n";
  
  return 0;
}  
