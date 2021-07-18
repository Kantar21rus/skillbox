#include <iostream>

void init(bool array[][10]) {
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j) {
      array[i][j] = false;
    }
  }
}

int input() {
  int i;
  bool cond = false;
  while (!cond) {
    std::cin >> i;
    if (i>=0 and i <= 9) {
      cond =true;
    } else {
      std::cout << "Out of range\n";
    }
  }
  return i;
}

void ship1(bool array[][10]) {
  int i,j;
  std::cout << "Input 4 ship size 1:\n";
  for (int k =0; k < 4; ++k) {
    i = input();
    j = input();
    if (array[i][j]) {
      std::cout << "Ship colusion, choose another place!\n";
      --k;
    } else {
      array[i][j] = true;
    }
  }
}

bool empty(bool cell) {
  if (!cell) {
    return true;
  }
  return false;
}

int horiz(bool array[][10], int c1, int c2, int cons) {
  int reverse = 0;
  for (int i=c1; i<= c2; ++i) {
    if (!array[cons][i]) {
      array[cons][i] = true;
      ++reverse;
    } else {
      for(;(i-1) >=c1; --i) {
	array[cons][i-1] = false;
      }
      std::cout << "Ship colusion, choose another place!\n";
      return 0;
    }
  }
  return reverse;
}

int vertic(bool array[][10], int c1, int c2, int cons) {
  int reverse = 0;
  for (int i=c1; i <= c2; ++i) {
    if (!array[i][cons]) {
      array[i][cons] = true;
      ++reverse;
    } else {
      for(;(i-1) >=c1; --i) {
	array[i-1][cons] = false;
      }
      std::cout << "Ship colusion, choose another place!\n";
      return 0;
    }
  }
  return reverse;
}

int shipSize(int size, bool array[][10]) {
  int ib, jb, ie, je, reverse;
  
  std::cout << "Input ship size " << size << ":\n";
  std::cout <<"Input Begin coordinats:\n";
  ib = input();
  jb = input();
  std::cout << "Input End coordinats:\n";
  ie = input();
  je = input();
  if ( ib==ie and jb!=je and ((je-jb)==(size-1))) {
    reverse = horiz(array, jb, je, ib);
  } else if (ib!=ie and jb==je and ((ie-ib)==(size-1))) {
    reverse = vertic(array, ib, ie, jb);
  } else {
    std::cout << "Wrong size or direction on ship!\n";
    return 0;
  }
  return (reverse == size) ? 1  : 0 ;
}

void output(bool array[][10]) {
  std::cout << "\n   0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9";
  std::cout << "\n------------------------------------------\n";
  for (int i=0; i<10; ++i) {
    std::cout << i <<"|";
    for (int j=0; j<10; ++j) {
      std::cout << " " <<(array[i][j] ? "O" : " ") << " |";
    }
    std::cout << "\n------------------------------------------\n";
  }
} 

void placement(bool array[][10]) {
  int ship2 = 0;
  int ship3 = 0;
  int ship4 = 0;
  ship1(array);
  while (ship2 != 3) {
    ship2 += shipSize(2,array);
    output(array);
  }
  while (ship3 != 2) {
    ship3 += shipSize(3,array);
    output(array);
  }
  while (ship4 != 1) {
    ship4 += shipSize(4,array);
    output(array);
  }
}

int shoot(bool array[][10]) {
  int i,j;
  std::cout << "Insert target\n";
  i = input();
  j = input();
  if (array[i][j]) {
    array[i][j] = false;
    std::cout << "Got!\n";
    return 1;
  } else {
    std::cout << "Miss!\n";
    return 0;
  }
}

int battle(bool player1[][10], bool player2[][10]) {
  int life1 =2;
  int life2 =2;
  for (int i=0;life1 != 0 or life2 != 0; ++i) {
    if ( i % 2 == 0) {
      std::cout << "Player1 shoot on Player2's fleet!\n";
      life2 -= shoot(player2);
      output(player2);
      if (life2 == 0) {
	return 1;
      }
    } else {
      std::cout << "Player2 shoot on Player1's fleet!\n";
      life1 -= shoot(player1);
      output(player1);
      if (life1 ==0) {
	return 2;
      }
    }
  }
}


int main() {
  int winner;
  bool field1[10][10];
  bool field2[10][10];
  init(field1);
  init(field2);
  std::cout << "Player 1 Placement:\n";
  placement(field1);
  std::cout << "Player 2 Placement:\n";
  placement(field2);
  winner = battle(field1, field2);
  std::cout << "Win this battle! Player " << winner << "\n";
}
  
