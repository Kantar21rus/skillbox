#include <iostream>

void init(bool field[][12]) {
  for (int i=0; i < 12 ; ++i) {
    for (int j = 0; j < 12; ++j) {
      field[i][j] = true;
    }
  }
}

void output(bool field[][12]) {
  std::cout << "------------------------\n";
  for (int i=0; i < 12 ; ++i) {
    for (int j = 0; j < 12; ++j) {
      std::cout << (field[i][j] == true ? "o" : "x") << " ";
    }
    std::cout << "\n";
  }
  std::cout << "------------------------\n";
}

int input(int count, bool field[][12]) {
  int iSt, jSt, iFn, jFn;
  do {
    std::cout << "Input Start pos:\n";
    std::cin >> iSt >> jSt;
  } while(!((iSt >= 0 and iSt <= 11) and (jSt >= 0 and jSt <= 11)));
  do {
    std::cout << "Input Finish pos:\n";
    std::cin >> iFn >> jFn;
  } while(!((iFn >= 0 and iFn <= 11) and (jFn >= 0 and jFn <= 11)));
  for (; iSt <= iFn ; ++iSt) {
    for (int j=jSt; j <= jFn; ++j) {
      if (field[iSt][j] == true) {
	field[iSt][j] = false;
	++count;
	std::cout << "Pop!\n";
      }
    }
  }
  return count;
}
  
int main() {
  bool field[12][12];
  int count = 0;
  init(field);
  while (count != 144) {
    output(field);
    count = input(count, field);
  }
  output(field);
}
