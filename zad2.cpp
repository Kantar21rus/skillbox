#include <iostream>

void output (char array[][3]){
  std::cout << "------\n";
  for (int i = 0; i <3; ++i) {
    for (int j =0 ; j <3 ; ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "------\n";
}

bool arrayAddres(int i, int j) {
  if (i < 0 or i > 2) return false;
  if (j < 0 or j > 2) return false;
  return true;
}

void input (int &countX,int &countO, char array[][3], bool fill[][3]) {
  int i,j;
  char turn;
  if (countX == countO) {
    ++countX;
    turn = 'X';
  } else {
    ++countO;
    turn = 'O';
  }
  std::cout << "Now turn: " << turn << "\n";
  do {
    std::cin >> i >> j;
  } while (!arrayAddres(i, j));
  
  if (!fill[i][j]) {
    array[i][j] = turn;
    fill[i][j] = true;
  } else {
    while (fill[i][j]) {
      std::cout << "Repeat turn: " << turn << "\n";
      do {
	std::cin >> i >> j;
      } while (!arrayAddres(i, j));
      }
    array[i][j] = turn;
    fill[i][j] = true;
  }  
}

bool horizWin(char array[][3]) {
  for (int k=0; k < 3; ++k) {      
    if (array[k][0] == array[k][1] and array[k][0] == array[k][2] and array [k][0] != ' ') {
      return true;
    }
  }
  return false;
}

bool verticWin(char array[][3]) {
  for (int k=0; k < 3; ++k) {      
    if (array[0][k] == array[1][k] and array[0][k] == array[2][k] and array [0][k] != ' ') {
      return true;
    }
  }
  return false;
}

bool haveWinner(int &countX, int &countO, char array[][3]) {
  bool notWinner = true;
  if (horizWin(array)) {
    return true;
  }
  if (verticWin(array)) {
    return true;
  }
  if (countX + countO == 9 and notWinner) {
    return false;
  }
  return false;
}

int main() {
  int countX =0;
  int countO =0;
  char field[3][3];
  bool fieldFill[3][3];
  for (int i = 0; i <3; ++i) {
    for (int j =0 ; j <3 ; ++j) {
      field[i][j] = ' ';
      fieldFill[i][j] = false;
    }
  }

  while(!haveWinner(countX, countO, field)) {
    input(countX, countO, field, fieldFill);
    output(field);
    if (haveWinner(countX, countO, field) and countX == (countO +1)) {
      std::cout << "Winner X\n";
    } else if (haveWinner(countX, countO, field) and countX == countO) {
      std::cout << "Winner O\n";
    } else if (!haveWinner(countX, countO, field) and (countX + countO) ==9 ) {
      std::cout << "Nobody\n";
      return 0;
    }
  }
  return 0;
}
  
