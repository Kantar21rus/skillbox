#include <iostream>



bool checkChar(char symbol) {
  if (symbol == '.' or (symbol >= 48 and symbol <=57)) return true;
  return false;
} 

int typeSwitch(std::string part) {
  int number = 0;
  for (int i=0; i < part.length(); i++) {
    number = number * 10 + (part[i] -48);
  }
  if (number == 0 and part.length() != 1) return 500;
  if (part.length() == 2 and number < 10) return 500;
  if (part.length() == 3 and number < 100) return 500;
  if (number < 0 or number > 255) return 500;
  return number;
}

bool checkCorrect(std::string ip) {
  std::string part1 = "";
  std::string part2 = "";
  std::string part3 = "";
  std::string part4 = "";
  int countDot = 0;
  int int1, int2, int3, int4 = 0;
  int dot1, dot2, dot3 = 0;
  
  for (int i=0; i < ip.length(); i++) {
    if (!checkChar(ip[i])) return false;
    if (ip[i] == '.') ++countDot;
    if (countDot == 0) part1 += ip[i];
    if (countDot == 1 and ip[i] != '.') part2 += ip[i];
    if (countDot == 2 and ip[i] != '.') part3 += ip[i];
    if (countDot == 3 and ip[i] != '.') part4 += ip[i];
  }
  if (countDot != 3) return false;
  int1 = typeSwitch(part1);
  int2 = typeSwitch(part2);
  int3 = typeSwitch(part3);
  int4 = typeSwitch(part4);
  
  if (int1 == 500 or int2 == 500 or int3 == 500 or int4 == 500) return false;
  
  return true;
}

int main() {
  std::string ip;

  std::cin >> ip;

  if (checkCorrect(ip)) {
    std::cout << "Yes\n";
  } else std::cout << "No\n";

}
