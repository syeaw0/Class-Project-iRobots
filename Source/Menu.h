// Menu.h

#ifndef MENU_H_
#define MENU_H_

//#define DEBUG_MENU_TRACE	// traces menu operations

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "input.h"

template <class T>
class Menu{
public:
	Menu();
	// Creates an empty menu of type <T>
	// Rules:
	//	- All menu options must be of the same type
	//	- [FIX] Evaluating an empty menu throws a vector error i think?
	//	- [FIX] Evaluating out of range is? (untested) [FIX LATER]
	//    ^^ I recommend using eval() w/o parameters to avoid this issue
	// Todo:
	//	- Description Text? [OPT]
	//	- Redesign? [OPT]

	Menu(std::string title);
	// Initialized with a title!

	~Menu();
	// I'm not sure why this is needed. Function pointers don't work w/o it

	// [ADD] Copy Constructor?
	// [ADD] Format Constructor?
	// [ADD] Menu Loop? Should it be handled here?

	void add( T function, std::string description);
	// Adds a Menu Option to the end of the Menu w/ a description
	//	T function is the output if this option is selected
	//	ex: desMenu.add(VERY, "Very Nice to Have");
	// 			// adds an option of this enum type
	//	ex: pamphletMenu.add( &Pamphlet::PrintContacts , "Key Customer");
	//			// adds an option of this function pointer

	void insert( T function, std::string decription);
	// Inserts a Menu Option at the start of the Menu w/ a description
	// ex: adminMenu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintCustomersByName ),  "Print Customers By Name");
	//			// casting function pointer for type consistency,

	T eval();
	T eval(int index);
	// Returns an option
	// 	 - eval() scans an integer for you
	// 	 - eval(int) evaluates at that specified index
	// ex: 	desirability = desMenu.eval(scanInt());
	// ex:	function = functionMenu.eval();
	//		(*function)();
	//		// runs a function based on the menu


	// Cosmetics o_o --------------------------------------------------
	//		I think overhead is generated from the template
	//		Writing template <class T> is strange
	//		Writing everything in the .h is strange
    //		-> all of these methods should be in another class? [OPT]

	void print();													// Prints a sick menu

	void setBorder(char);											// Border character (all the same)
	void setBorder(char left, char right, char top, char bottom); 	// Border characters
	void setMargins(int left, int right, int top, int bottom);		// Sets Margins
	//	left and right count spaces, top and bottom count lines

	void setFormatOption(std::string, std::string, std::string);	// Line formatting
	//	before, between, and after
	void setLinesBefore(int);				// Sets # empty lines before option
	void setLinesAfter(int);				// Sets # empty lines after option
	//  not sure how these should work
	void setWidth(int);							// Sets menu

	void setTitle(std::string);				// Sets the title
	void setPrompt(std::string);			// Sets the inputs prompt ("enter a number")
	void setErrorMessage(std::string); 		// message you get for inputing a bad index
	void setDescription(std::string);		// [ADD] some help text?

private:
	struct Option;
	// Option struct contains a value and a description
	// note this might make the compiler explode? [TEST]
	//		if it does then make this a global struct

	std::vector<Option> options;
	// ^^ Menu is based entirely around this

	// Cosmetics
	int width, linesBefore, linesAfter;
	int marLeft, marRight, marTop, marBot;
	char bLeft, bRight, bTop, bBot;
	std::string textError, textDescription, textTitle, textPrompt;
	std::string optBefore, optMiddle, optAfter;

	void init();
	void printLines(int);
	void printN(char, int); // prints N characters
};


/* SAMPLE:

menu class code:	// this might not work; I haven't tried it

	Menu<Interest> iMenu("Customer's interest level in iRobotsTheBomb");

	iMenu.add(VERY, "Very Interested");
	iMenu.add(SOMEWHAT, "Somewhat Interested");
	iMenu.add(NO, "Not Interested");
	iMenu.add(NEVER_CALL, "Never Call");
	//iMenu.setPrompt("Enter Number: "); //default prompt

	iMenu.print();

	aCustomer.interestLvl = interestMenu.eval();


traditional menu code:

	try {
		cout << "\nCustomer's interest level in iRobotsTheBomb\n"
				"0 - Very Interested\n"
				"1 - Somewhat Interested\n"
				"2 - Not Interested\n"
				"3 - Never Call\n"
				"Enter Number: ";

		// INPUT - Get input & check if valid
		if(!(inStream >> ratingNum))
		{
			inStream.clear();
			inStream.ignore(numeric_limits<streamsize>::max(), '\n');
			throw ratingNum;
		}
		// PROCESSING - Check if valid choice
		else if(ratingNum < 0 || ratingNum > 3)
		{
			throw ratingNum;
		}
		else
		{
			// PROCESSING - Get interest level
			invalid = false;
			switch(ratingNum)
			{
				case 0	: 	aCustomer.interestLvl = VERY;
							break;
				case 1	: 	aCustomer.interestLvl = SOMEWHAT;
							break;
				case 2	: 	aCustomer.interestLvl = NO;
							break;
				case 3	: 	aCustomer.interestLvl = NEVER_CALL;
							break;
				default	: 	break;
			}
		}
	}

	// OUTPUT - Tell user that interest level is not valid
	catch(int caughtInterest)
	{
		invalid = true;
		cout << "Invalid customer interest level: " << caughtInterest << endl;
	}

 */



// Implementation

template <class T>
struct Menu<T>::Option{
	T value;
	std::string desc;
	Option(T inValue, std::string inDesc) : value(inValue), desc(inDesc){};
};


template <class T>
Menu<T>::Menu(){
	init();
}

template <class T>
Menu<T>::Menu(std::string initTitle) {
	init();
	setTitle(initTitle);
}

template <class T>
void Menu<T>::init(){	// workaround for delegating constructor
	setWidth(75);
	setLinesBefore(1);
	setLinesAfter(0);
	setBorder('>', '<', '*', '*');
	setMargins(6, 6, 1, 1);
	setErrorMessage("Not a valid number");
	//setDescription("Input a number");
	setTitle("Title");
	setPrompt("Enter a Number: ");
	setFormatOption("", " - ", "");

	options.reserve(16);
}

template <class T>
Menu<T>::~Menu(){
}

template <class T>
void Menu<T>::add(T function, std::string desc){
	#ifdef DEBUG_MENU_TRACE
		printf("adding menu option %s\n", desc.c_str());
	#endif
	options.push_back(Option(function, desc));
}

template <class T>
void Menu<T>::insert(T function, std::string desc){
	#ifdef DEBUG_MENU_TRACE
		printf("inserting menu option %s\n", desc.c_str());
	#endif
	options.insert(options.begin(), Option(function, desc));
}

template <class T>
T Menu<T>::eval(){
	int index = input::scanIntPrompt(textPrompt, textError ,0, options.size()-1);
	std::cin.ignore();
	return options[index].value;
}

template <class T>
T Menu<T>::eval(int index){
	return options[index].value;
}

template <class T>
void Menu<T>::print(){	// Print menu function
	using namespace std;

	// Top Border
	printN(bTop, width);
	cout << endl;

	// Top Margin
	printLines(marTop);

	// Title
	cout << bLeft;
	printN(' ', marLeft);
	int extras = width - marLeft - marRight - 2 - textTitle.length();
	printN(' ', extras/2);
	cout << textTitle;
	printN(' ', extras - extras/2);
	printN(' ', marRight);
	cout << bRight << endl;

	// Space after title [OPT]
	// printLines(1);

	// Options Body
	for(int index = 0; index < options.size(); index++){

		// Top Space
		printLines(linesBefore);

		//Option
		cout << bLeft;
		printN(' ', marLeft);
		cout << optBefore;
		printf("%2d", index);
		cout << optMiddle << options[index].desc << optAfter;
		printN(' ', width - 2 - marLeft - optBefore.length() - 2 - optMiddle.length() - options[index].desc.length() - optAfter.length());
		// this is basically (width - everything) to fill in the extra space
		cout << bRight;
		cout << endl;

		// Bottom Space
		printLines(linesAfter);
	}

	// Bottom Margin
	printLines(marBot);

	// Bottom Border
	printN(bBot, width);
	cout << endl;
}

// Accessors painfully redundant
template <class T> void Menu<T>::setBorder(char newBorder){
	bLeft = bRight = bTop = bBot = newBorder;
}
template <class T> void Menu<T>::setBorder(char left, char right, char top, char bottom){
	bLeft = left;
	bRight = right;
	bTop = top;
	bBot = bottom;
}
template <class T> void Menu<T>::setMargins(int left, int right, int top, int bottom){
	marLeft = left;
	marRight = right;
	marTop = top;
	marBot = bottom;
}
template <class T> void Menu<T>::setFormatOption(std::string a, std::string b, std::string c){
	optBefore = a;
	optMiddle = b;
	optAfter = c;
}
template <class T> void Menu<T>::setLinesBefore(int a){
	linesBefore = a;
}
template <class T> void Menu<T>::setLinesAfter(int a){
	linesAfter = a;
}
template <class T> void Menu<T>::setWidth(int a){
	width = a;
}
template <class T> void Menu<T>::setTitle(std::string a){
	textTitle = a;
}
template <class T> void Menu<T>::setErrorMessage(std::string a){
	textError = a;
}
template <class T> void Menu<T>::setDescription(std::string a){
	textDescription = a;
}
template <class T> void Menu<T>::setPrompt(std::string a){
	textPrompt = a;
}


// Generic Print Functions
template <class T> void Menu<T>::printN(char c, int n){
	for(int i=0; i<n; i++){
		std::cout << c;
	}
}
template <class T> void Menu<T>::printLines(int n){
	for(int i=0; i<n; i++){
		std::cout << bLeft;
		printN(' ', width-2);
		std::cout << bRight << std::endl;
	}
}

#endif /* MENU_H_ */
