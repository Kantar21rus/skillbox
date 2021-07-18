#include <iostream>

void output (std::string name, int array[2][6]) {
  std::cout << name <<"\n-----------------------------------------\n";
  for (int i=0; i < 2 ; ++i) {
    for (int j=0; j < 6; ++j) {
      std::cout << array[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "+++++++++++++++++++++++++++++++++++++++++\n";
}

int main() {
  int plates[2][6];
  int seats[2][6];
  int spoons[2][6];
  for (int i=0; i < 2 ; ++i) {
    for (int j=0; j < 6; ++j) {
      if (j == 0) {
	spoons[i][j] = 4;
	plates[i][j] = 3;
      } else {
	spoons[i][j] = 3;
	plates[i][j] = 2;
      }
      seats[i][j] = 1;
    }
  }
  std::cout << "Was:\n";
  output("Spoons", spoons);
  output("Plates", plates);
  output("Seats", seats);

  seats[0][4] +=1;
  spoons[1][0] -=1;
  plates[1][0] -=1;
  
  std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\nNow:\n";
  output("Spoons", spoons);
  output("Plates", plates);
  output("Seats", seats);

}

  
      
      
      
