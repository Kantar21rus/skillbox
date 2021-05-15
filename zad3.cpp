#include <iostream>


int main() {
  int countFloor = 5;
  int countPeopleRegistr;
  int peopleFloor[countFloor];
  int countPeopleNow = 0;

  std::cout << "Number of residents: ";
  std::cin >> countPeopleRegistr ;
  
  for (int i = 0; i < countFloor; i++) {
    std::cout << "Number of residents on floor " << i+1 << ": ";
    std::cin >> peopleFloor[i];
    countPeopleNow += peopleFloor[i];
		 
  }

  std::cout << "Isolation level: " << ((float)  countPeopleNow * 100) / (float) countPeopleRegistr << "\n";

      
}
