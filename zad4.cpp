#include <iostream>

void input(int matrix[][4]) {
  int inp;
  for (int i=0; i<4; ++i) {
    for (int j=0; j<4; ++j) {
      std::cin >> inp;
      matrix[i][j] = inp;
    }
  }
  std::cout << "---------\n";
}

bool equal(int mat1[][4], int mat2[][4]) {
  for (int i=0; i<4; ++i) {
    for (int j=0; j<4; ++j) {
      if (mat1[i][j] != mat2[i][j]) {
	return false;
      }
    }
  }
  return true;
}

int main() {
  int matA[4][4];
  int matB[4][4];

  input(matA);
  input(matB);

  if (equal(matA, matB)) {
    std::cout << "Matrix equal!\n";
  } else {
    std::cout << "Matrix different!\n";
  }
}
