#include <iostream>

std::string getline() {
  std::string line1;
  std::string line2;
  std::string line3;
  std::string line;
  
  std::cin >> line1 >> line2 >> line3;
  line = line1 + line2 + line3;
  if (line1.length() != 3) return "Incorrect";
  if (line2.length() != 3) return "Incorrect";
  if (line3.length() != 3) return "Incorrect";
  for (int i =0; i < 9; ++i) {
    if (line[i] != 'X' and line[i] != 'O' and line[i] != '.') return "Incorrect";
  }
  return line;
}

int countChar(std::string line, char letter) {
  int count = 0;
  for (int i = 0 ; i < line.length(); ++i) {
    if (line[i] == letter) count++;
  }
  return count;
}

bool compare(char c1, char c2, char c3) {
  if (c1 == c2 and c1 == c3 and c1 !='.') return true;
  return false;
}

int horiz(std::string line) {
  int output = 0;
  std::string newLine = "";
  for (int n = 0; n < 9 ; n += 3) {
    for (int i = n ; i < (n+3) ; i++) {
      newLine += line[i];
    }
    if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'X') output += 10; 
    if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'O') output += 50;
    newLine = "";
  }
  return output;
}

int vertic(std::string line) {
  int output = 0;
  std::string newLine = "";
  for (int n = 0; n < 3 ; n++) {
    for (int i = n ; i < 9 ; i += 3) {
      newLine += line[i];
    }
    if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'X') output += 10; 
    if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'O') output += 50;
    newLine = "";
  }
  return output;
}

int diag(std::string line) {
  int output = 0;
  std::string newLine = "";
  for (int i = 0 ; i < 9 ; i += 4 ) {
    newLine += line[i];
  }
  if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'X') output += 10; 
  if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'O') output += 50;
  newLine = "";
  for (int i = 6 ; i > 1 ; i -= 2 ) {
    newLine += line[i];
  }
  if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'X') output += 10; 
  if (compare(newLine[0], newLine[1], newLine[2]) and newLine[0] == 'O') output += 50;
  return output;
}
   

int whoWin(std::string line) {
  int winCond = 0 ;
  winCond = horiz(line) + vertic(line) + diag(line);
  return winCond;
}
  

int main() {

  std::string line;
  int countX = 0;
  int countO = 0;
  int winnerNumber = 0;
  std::string winner;
  
  line = getline();

  countX = countChar(line, 'X');
  countO = countChar(line, 'O');

  winnerNumber = whoWin(line);

  if (winnerNumber == 0) {
    winner = "Nobody";
  } else if (winnerNumber == 10 and countX == (countO + 1)) {
    winner = "Petya won";
  } else if (winnerNumber == 50 and countX == countO ) {
    winner = "Vanya won";
  } else winner = "Incorrect";
			 
  
  std::cout << winner  << "\n";

}
