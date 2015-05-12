// input.h

#ifndef INPUT_H_
#define INPUT_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <ios>
#include <limits>

namespace input{
	void dumpLine(std::istream&);	// fix for getline() '\n' issue, called between cin/scanf and getline calls

	void specialFlush(FILE*);
	int scanInt();
	int scanIntRange(int min, int max);
	int scanIntPrompt(std::string prompt, std::string error, int min, int max);
	char scanChar(std::string prompt, std::string error, char check1, char check2);

	std::string scanString(std::string prompt);
	std::string scanName();		// line names
}

#endif /* INPUT_H_ */
