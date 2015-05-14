// input.cpp

#include "input.h"

void input::dumpLine(std::istream& str){
	using namespace std;
	str.ignore(numeric_limits<streamsize>::max(), '\n');
}
void input::specialFlush(FILE* f){
	fscanf(f, "%*[^\n]%*c");
}

int input::scanInt(){
	int input;
	bool success = false;
	do{
		if( scanf("%d", &input) == 0){
			specialFlush(stdin);
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
			specialFlush(stdin);
			continue;
		}
		success = input >= min && input <= max;
		// if(failScan) printf("Invalid Input\n"); // [OPT]
	}
	while(!success);
	return input;
}

int input::scanIntPrompt(std::string prompt, std::string error, int min, int max)
{
	int input;
	bool success = false;
	do
	{
		printf(prompt.c_str());

		if( scanf("%d", &input) == 0)
		{
			specialFlush(stdin);
			std::cout << error << '\n';
			continue;
		}
		success = input >= min && input <= max;
		if(!success) std::cout << error << "\n";
	}
	while(!success);
	return input;
}


std::string input::scanName(){
	std::string inName;
	std::cout << "Enter Name: ";
	std::getline(std::cin, inName);

	// trimming here?
	//		char length
	//		# words
	//		special characters

	return inName;
}

std::string input::scanString(std::string prompt){
	std::string inString;
	std::cout << prompt;
	std::getline(std::cin, inString);

	return inString;
}

char input::scanChar(std::string prompt, std::string error, char check1, char check2){
	char inChar;
	bool success = false;
	do{
		std::cout << prompt;
		std::cin.get(inChar);
		std::cin.ignore(1000, '\n');
		inChar = toupper(inChar);

		success = (inChar == check1 || inChar == check2);
			if(!success)
			{
				std::cout << error << '\n';
			}
	}
	while(!success);

	return inChar;
}
