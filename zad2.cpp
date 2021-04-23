#include <iostream>

bool charCheckFPart(char in) {
  if (in == 33 or (in >=35 and in <=39) or in == 42 or in == 43 or ( in >= 45 and in <= 57 ) or ( in >= 63 and in <= 90) or ( in >=94 and in <= 126)) return true;
  return false;
}

bool charCheckBPart(char in) {
  if (in == 45 or in == 46 or ( in >= 48 and in <= 57 ) or ( in >= 65 and in <= 90) or ( in >=97 and in <= 122)) return true;
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
