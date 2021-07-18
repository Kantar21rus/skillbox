#include <iostream>

void input(double matrix[][4],double vector[]){
  double inp;
  std::cout << "Input Matrix:\n";
  for (int i=0; i < 4; ++i) {
    for (int j=0; j <4; ++j) {
      std::cin >> inp;
      matrix[i][j] = inp;
    }
  }
  std::cout << "Input Vector:\n";
  for (int i=0; i <4; ++i) {
    std::cin >> inp;
    vector[i] = inp;
  }
}


void multip (double matrix[][4],double vector[], double result[]){
  for (int i = 0; i < 4 ; ++i ) {
    double sum = 0;
    for (int j = 0; j < 4; ++j ) {
      sum += (matrix[i][j] * vector[j]);
    }
    result[i] = sum;
  }

}


void outputR(double result[]){
  std::cout << "Result:\n";
  for (int i = 0; i < 4; ++i) {
    std::cout << result[i] << "\n";
  }
}


int main() {
  double matrix[4][4];
  double vector[4];
  double result[4];

  input(matrix, vector);
  multip(matrix, vector, result);
  outputR(result);

}
