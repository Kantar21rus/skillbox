#include <iostream>
#include <vector>

int main() {
  std::vector<double> price{2.5, 4.25, 3.0, 10.0};
  std::vector<int> buyList{1,1,0,3};
  double sum = 0;
  for (int i=0; i < buyList.size(); ++i) {
    sum += price[buyList[i]];
  }
  std::cout << sum << "\n";

  return 0;
}
