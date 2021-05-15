#include <iostream>


int main() {
  int store[1];
  int gym[2];
  int cottage[3];
  int house[15];
  int skyscraper[50];
  float average;

  average = ((float) (sizeof(store) + sizeof(gym) + sizeof(cottage) + sizeof(house) + sizeof(skyscraper)))/((float) (sizeof(int) * 5));

  std::cout << "Average floor " << average << "\n";
}
  
  
  
