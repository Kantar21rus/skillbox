#include <iostream>

void output(double matrix[][4]) {
  for(int i=0; i < 4; ++i) {
    for (int j=0; j <4; ++j) {
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << "\n";
  }
}
  
void input(double matrix[][4]) {
  double inp;
  for(int i=0; i < 4; ++i) {
    for (int j=0; j <4; ++j) {
      std::cin >> inp;
      matrix[i][j] = inp;
    }
  }
  std::cout << "Matrix input:\n-------------\n";
  output(matrix);
  std::cout << "-------------\n";
}

void transform(double matrix[][4]) {
  for(int i=0; i < 4; ++i) {
    for (int j=0; j <4; ++j) {
      if (i != j) { 
	matrix[i][j] = 0;
      }
    }
  }
  std::cout << "Matrix Output:\n-------------\n";
  output(matrix);
}

int main() {
  double matrix[4][4];
  input(matrix);
  transform(matrix);
}
  
