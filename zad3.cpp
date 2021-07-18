#include <iostream>


int main() {
  int array[5][5];
  int number =0;
  int i=0;
  int j=0;
  
  for(;i < 5; ++i) {
    for(;j < 5; ++j){
      array[i][j]= number;
      ++number;
    }
    ++i;
    --j;
    for(;j >=0 and i <5 ; --j){
      array[i][j]= number;      
      ++number;
    }
    ++j;
  }

  for(int i=0 ;i < 5; ++i) {
    for(int j=0 ;j < 5; ++j){
      std::cout << array[i][j] << "\t";
    }
    std::cout << "\n";
  }
		    
}
  
