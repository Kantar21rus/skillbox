#include <iostream>



int main() {
  float frequency[10];
  bool chSt;

  std::cout << "Turning on the receiver\n";
  std::cout << "Tuning frequency\n";

  for (int i = 0; i < 10; i++ ) {
    std::cin >> frequency[i];
    if (!(frequency[i] > 0 and frequency[i] <= 200)) --i;
  }

  
  for ( int i = 0 ;;) {
    chSt = false;
    float changeFrequency;
    std::cout << "Play station on frequency " << frequency[i] << "\n";
    std::cout << "Enter frequency for change...\n";
    std::cin >> changeFrequency;
    if (changeFrequency == 0) break;
    for( int n =0 ; n < 10; n++) {
      if (changeFrequency == frequency[n]) {
	i = n;
	chSt = true;
	break;
      }
    
    }
    if (!chSt) { 
      std::cout << "This frequency empty\n";
      std::cout << "--------------------\n";
    } 
  }

  std::cout << "Turn OFF radio\n";
  
}
