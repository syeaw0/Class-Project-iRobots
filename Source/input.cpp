// input.cpp

#include "input.h"

void input::dumpLine(std::istream& str){
	using namespace std;
	str.ignore(numeric_limits<streamsize>::max(), '\n');
}

int input::scanInt(){
	int input;
	bool success = false;
	do{
		if( scanf("%d", &input) == 0){
			fflush(stdin);
			continue;
		}
	}
	while(!success);
	return input;
}

int input::scanIntRange(int min, int max){
	int input;
	bool success = false;
	do{
		if( scanf("%d", &input) == 0){
			fflush(stdin);
			continue;
		}
		success = input >= min && input <= max;
		// if(failScan) printf("Invalid Input\n"); // [OPT]
	}
	while(!success);
	return input;
}

int input::scanIntPrompt(std::string prompt, std::string error, int min, int max){
	int input;
	bool success = false;
	do{
		std::cout << prompt;
		if( scanf("%d", &input) == 0){
			fflush(stdin);
			std::cout << error;
			continue;
		}
		success = input >= min && input <= max;
		if(!success) std::cout << error;
	}
	while(!success);
	return input;
}


std::string input::scanName(){
	std::string inName;
	std::getline(std::cin, inName);

	// trimming here?
	//		char length
	//		# words
	//		special characters

	return inName;
}
