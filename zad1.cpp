#include <iostream>

char shiftLetter(char letter, int number) {
	int sum = 0;
	if (letter >= 'a' && letter <= 'z' ) {
		sum = (int) letter + number;
		if (sum < 97) {
			letter = (123 -(97 - sum));
		} else if ( sum > 122 ) {
			letter = (97 - (123 - sum));
		} else {
			letter = sum;
		}
	} else if (letter >= 'A' && letter <= 'Z' ) {
		sum = (int) letter + number;
		if (sum < 65) {
			letter = (91 -(65 - sum));
		} else if ( sum > 90 ) {
			letter = (65 - (91 - sum));
		} else {
			letter = sum;
		}
	} else letter = ' ';
	return letter;
}

std::string encrypt_caesar(std::string line, int number) {
	
	std::string newLine = "";
	
	for (int i = 0 ; i < line.length() ; ++i ) {
		char letter = line[i];
		newLine += shiftLetter(letter, number);
	}
	return newLine;
}

std::string decrypt_caesar(std::string line, int number) {
	number = - number;
	std::string output = encrypt_caesar(line, number);
	return output;
}


int main() {
	int number;
	std::string line;
	std::cout << "Insert your string and number for shift :\n";
	std::getline(std::cin, line);
	std::cin >> number;
	
	std::string newLine = encrypt_caesar(line, number);
	
	std::cout << "String after encrypt: " << newLine << "\n";
	
	newLine = decrypt_caesar(newLine, number);
	
	std::cout << "String after decrypt: " << newLine << "\n" ;
	return 0;
}
