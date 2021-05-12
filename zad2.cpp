#include <iostream>

bool charCheckFPart(char in) {
  if (in == '!' or (in >='#' and in <='\'') or in == '*' or in == '+' or ( in >= '-' and in <= '9' ) or ( in >= '?' and in <= 'Z') or ( in >='^' and in <= '~')) return true;
  return false;
}

bool charCheckBPart(char in) {
  if (in == '-'  or in == '.' or ( in >= '0' and in <= '9' ) or ( in >= 'A' and in <= 'Z') or ( in >='a' and in <= 'z')) return true;
  return false;
}

bool checkDot(std::string addres) {
  int last = addres.length() - 1 ;
  if (addres[0] == '.' or addres[last] == '.') return false;
  for (int i = 1; i < last; ++i) {
    if ( addres[i] == '.' and addres[i+1] == '.') return false;
  }
  return true;
}

bool checkCorrect(std::string addres) {
  int countDog = 0;
  int countDot = 0;
  std::string fPart = "";
  std::string bPart = "";
  
  for (int i = 0 ;  i < addres.length() ; ++i) {
    if (!charCheckFPart(addres[i])) return false;
    if (addres[i] == 64) ++countDog;
  }

  for (int i = 0 ; addres[i] != 64 ; ++i) {
    fPart += addres[i];
  }
  for (int i = (fPart.length() + 1); i < addres.length(); ++i) {
    bPart += addres[i];
    if (!charCheckBPart(addres[i])) return false;
  }
  if (fPart.length()>= 64 or fPart.length() < 1) return false;
  if (bPart.length()>= 63 or bPart.length() < 1) return false;
  
  if (!checkDot(addres)) return false;
  if (countDog != 1) return false;
  return true;
}

int main() {
  std::string addres;

  std::cin >> addres;

  if (checkCorrect(addres)) {
    std::cout << "Yes\n";
  } else std::cout << "No\n";

}
