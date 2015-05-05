/*********************************************************
* Team Awesome
**********************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
#include <sstream>
#include "Pamphlet.h"
using namespace std;

//makes the menu selections correspond to numbers
enum MenuOptions
{
	EXIT_MENU,			// to exit program
	CREATE_LIST,    // to create list of person info
	DISPLAY,		// to display the list in alphabetical order
	DISPLAY_REV,    // to display the list in reverse alphabetical order
	IS_EMPTY,       // to check if list is empty
	NAME_SEARCH,    // to search for a name
	REMOVE,			// to remove a person from the list
	CLEAR           // to clear a list
};

//info for a PersonRecord in a linked list
enum HelpMenu
{
	EXIT,
	ORDER_PAMPHLET,
	ORDER_ROBOT,
	READ_TESTIMONIALS,
	SUBMIT_TESTIMONIAL,
	CONTACT_US
};

/*************************************************************************
 * FUNCTION StringConvert
 * This function converts an integer to a string
 *
 * -> RETURNS: corresponding string
 ************************************************************************/
string StringConvert (int integer);

/**************************************************************************
 * FUNCTION GetAndCheckInput
 *   This function prompts and reads an input value from the user and error
 *   checks until the input value is a valid entry
 *
 * RETURN : valid input command
**************************************************************************/
int GetAndCheckInput(const string PROMPT,     // OUT - input prompt
                     const int    MIN_VAL,    // CALC & OUT - minimum value
                     const int    MAX_VAL);   // CALC & OUT - maximum value

/**************************************************************************
* Ellipsis
*  This function accepts in a string and maximum length, and then modifies
*  the string to truncate at the maximum length and replaces the last 3
*  characters in the string with "...".
*
* RETURNS: modified string ready for output
**************************************************************************/
string Ellipsis(string inputStr,    //CALC - input string
                int    maxLength);  //CALC - max length of one line

#endif /* HEADER_H_ */
