#include <iostream>

std::string inputNumber() {
  std::string number;
  std::string middle = "";
  std::string mantis = ".";
  bool cond = true;
  bool dot = false;
  int counterDot = 0;
  int dotPlace = 0;
  std::cin >> number;
  char begin = number[0];
  if (number[0] == '.') {
    begin = '0';
  }  
  for (int counter = 0 ;counter < number.length() ; ++ counter  ) {
    if (number[counter] == '.' ) {
      dot = true;
      ++counterDot;
      dotPlace = counter;
    }
  }
  int addcounter = 0;
  if (dot ) {
    for (int i = 1 ; i < dotPlace ; ++i) {
      middle += number[i];
      if (number[i] < '0' || number[i] > '9' ) {
        cond = false;
      } else ++addcounter;
    }
    for (int i = dotPlace + 1; i < number.length() ; ++i) {
      mantis += number[i];
      if (number[i] < '0' || number[i] > '9' ) {
        cond = false;
      } else ++addcounter;
    }    
  } else {
    for (int i = 1 ; i < number.length() ; ++i) {
      middle += number[i];
      if (number[i] >= '0' && number[i] <= '9' ) {
        ++addcounter;
      } else cond = false;
    }
    mantis ="";
  }
  if (begin >= '0' && begin <= '9') {
    ++addcounter;
  }
  std::string res = "";
  res += begin;
  res += middle;
  res += mantis;
  if ( ((begin >= '0' && begin <= '9') || begin == '-' ) && counterDot < 2 && cond && addcounter > 0 && res != "0.") {
    return res;
  } else {
    return "ERROR";
  }
}

unsigned long long intPart(std::string num) {
  std::string intPartS ="";
  unsigned long long intPartN = 0;
  for (int i=0; i < num.length() and num[i] != '.'; ++i) {
    intPartS += num[i];
  }
  for (int i=0; i < intPartS.length(); ++i) {
    intPartN = intPartN * 10 + (intPartS[i] - 48);
  }
  return intPartN;
}

std::string floatPart(std::string num) {
  std::string floatPartS ="";
  unsigned long long floatPartN = 0;
  int dotPos = 0;
  for (int i=0; i <num.length() and num[i] != '.'; ++i) {
    dotPos++;
  }
  dotPos++;
  for (int i=dotPos; i < num.length(); ++i) {
    floatPartS += num[i];
  }
  return floatPartS;
}

std::string nulAdd(std::string fp, int mine, int alien) {
  for (int i = (mine - 1); i < (alien -1) ; ++i) {
    fp += '0';
  }
  return fp;
}

std::string floatCompare(std::string fp1, std::string fp2) {
  int longfp1 = fp1.length();
  int longfp2 = fp2.length();

  if (longfp1 == longfp2) {
    for (int i = 0; i < longfp1; ++i) {
      if ( fp1[i] > fp2[i]) return "More";
      if ( fp1[i] < fp2[i]) return "Less";
    }
    return "Equal";
  } else if (longfp1 > longfp2) {
    fp2 = nulAdd(fp2, longfp2, longfp1);
    for (int i = 0; i < longfp1; ++i) {
      if ( fp1[i] > fp2[i]) return "More";
      if ( fp1[i] < fp2[i]) return "Less";
    }
    return "Equal";
  } else if (longfp1 < longfp2) {
    fp1 = nulAdd(fp1, longfp1, longfp2);
    for (int i = 0; i < longfp2; ++i) {
      if ( fp1[i] > fp2[i]) return "More";
      if ( fp1[i] < fp2[i]) return "Less";
    }
    return "Equal";
  }
  return "Error";
}

std::string equalPosiv(std::string num1, std::string num2) {
  std::string result;
  unsigned long long intPart1 = intPart(num1);
  unsigned long long intPart2 = intPart(num2);
  std::string floatPart1 = floatPart(num1);
  std::string floatPart2 = floatPart(num2);
  if (intPart1 > intPart2) return "More";
  if (intPart1 < intPart2) return "Less";
  if (intPart1 == intPart2) {
    result = floatCompare(floatPart1, floatPart2);
  }
  return result;
}

std::string equalNegativ(std::string num1, std::string num2) {
  num1[0] = '0';
  num2[0] = '0';
  std::string result = equalPosiv(num1, num2);
  if (result == "More") {
    result = "Less";
  } else if (result == "Less") {
    result = "More";
  } else if (result == "Equal") {
    result = "Equal";
  } else result = "ERROR";
  return result;
}

bool specialCondition(std::string num1, std::string num2) {
  if ( (num1.length() == 2 and num1[0] == '-' and num1[1] == '0' and num2[0] and num2.length() == 1) or (num2.length() == 2 and num2[0] == '-' and num2[1] == '0' and num1[0] == '0' and num1.length() == 1 )) return true;
  return false;
}

std::string equal(std::string num1, std::string num2) {
  std::string result;
  if (specialCondition(num1, num2)) return "Equal";
  if (num1[0] != '-' and num2[0] == '-') return "More";
  if (num1[0] == '-' and num2[0] != '-') return "Less";  
  
  result = (num1[0] != '-' and num2[0] != '-' ? equalPosiv(num1, num2) : equalNegativ(num1, num2));
  return result;
} 

int main(){
  std::string number1;
  std::string number2;

  std::cout << "Insert first number: ";
  number1 = inputNumber();
  std::cout << "Insert second number: ";
  number2 = inputNumber();

  if (number1 =="ERROR" or number2 == "ERROR") {
    std::cout << "ERROR" << "\n";
  } else {
    std::cout << equal(number1, number2) << "\n";
  }
}
