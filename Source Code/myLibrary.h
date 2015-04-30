/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * ASSIGN # 14	: Linked Lists
 * CLASS		: CS1C
 * DUE DATE		: 4/28/15
 **********************************************/

#ifndef MYLIBRARY_H_
#define MYLIBRARY_H_

// PRE-PROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************
 * NAMESPACE myLibrary
 * -------------------------------------------------------
 * This namespace is a collection of all my functions and
 * classes
 *********************************************************/
namespace myLibrary
{
/*****************************************************************
 * FUNCTION PrintHeader
 * ---------------------------------------------------------------
 * This function will accept the name, type, and number of an
 * 	assignment and outputs the result to a user specified
 * 	destination.
 * 		- Returns nothing
 *****************************************************************/

void PrintHeader(string    asName, 	// IN - The name of the assignment
		 	 	 char      asType, 	// IN - The type of assignment
		 	 	 	 	 			//	  - (LAB or ASSIGNMENT)
		 	 	 int       asNum,	// IN - The number of the assignment
		 	 	 ostream& output);	// IN - The file to output to

/**************************************************
 * WordWrap
 * ------------------------------------------------
 * This function wraps the text around a specified
 * limit
 **************************************************/

void WordWrap(string  text, 	// IN   - The text to word wrap
			  int     maxLen,	// CALC - The maximum characters in a line
			  ostream &oFile);	// OUT 	- The file to output to
};

/*****************************************************************
 * FUNCTION PrintHeader
 * ---------------------------------------------------------------
 * This function will accept the name, type, and number of an
 * 	assignment and outputs the result to a user specified
 * 	destination.
 * 		- Returns nothing
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 * 		asName		: Assignment Name must be previously defined
 * 		asType		: Assignment Type must be previously defined
 * 		asNum		: Assignment Number must be previously defined
 *
 * POST-CONDTITIONS
 * 		<None. Outputs the class header>
 *****************************************************************/

void myLibrary::PrintHeader(string    asName, 	// IN - The name of the assignment
		 	 	 	 	    char      asType, 	// IN - The type of assignment
		 	 	 	 	 			//	  - (LAB or ASSIGNMENT)
							int       asNum,	// IN - The number of the assignment
							ostream& output)	// IN - The file to output to
{
	/*************************************************************
	* CONSTANTS
	* ------------------------------------------------------------
	* USED FOR FORMATTING CLASS HEADER
	* ------------------------------------------------------------
	* CLASS_HEADER_OUTPUT	: The spacing for the class header
	* ASSIGN_HEADER_OUTPUT	: The spacing for the assignment
	* LAB_HEADER_OUTPUT		: The spacing for the lab
	**************************************************************/

	// Class Header

	const int   CLASS_HEADER_OUTPUT		= 14;
	const int   ASSIGN_HEADER_OUTPUT	= 6;
	const int   LAB_HEADER_OUTPUT		= 9;

	// OUTPUT - Outputs the class header to a file

	output << left;
	output << "*************************************************";
	output << "\n* PROGRAMMED BY : " "Samuel Yeaw";
	output << "\n* " << setw(CLASS_HEADER_OUTPUT) << "CLASS" << ": "
		    << "CS1C";
	output << "\n* " << setw(CLASS_HEADER_OUTPUT) << "SECTION" << ": "
		    << "MW; 12:30 - 4:20";

	if(toupper(asType) == 'L')
	{
		output << "\n* LAB #" << setw(LAB_HEADER_OUTPUT);
	}
	else
	{
		output << "\n* ASSIGN #" << setw(ASSIGN_HEADER_OUTPUT);
	}
	output << asNum << ": " << asName;
	output << "\n************************************************\n\n";
	output << right;
}

/**************************************************
 * WordWrap
 * ------------------------------------------------
 * This function wraps the text around a specified
 * limit
 * ------------------------------------------------
 * PRE-CONDITIONS
 * 	text	: The text to word wrap
 * 	maxLen	: The maximum character limit in a line
 * 	oFile	: The output file
 *
 * POST-CONDITIONS
 * 	<Outputs the modified text>
 **************************************************/

void myLibrary::WordWrap(string  text, 	// IN   - The text to word wrap
			  	  	     int     maxLen,	// CALC - The maximum characters in a line
						 ostream &oFile)	// OUT 	- The file to output to
{
	string word;
	string line;
	int    textLen;
	int    count;

	textLen = text.length();

	for(count = 0; count <= textLen + 1; count++)
	{
		if(!isspace(text[count]) && count < textLen)
		{
			word += text[count];
		}
		else
		{
			if(line.length() + word.length() > (unsigned int)maxLen
			   || count == textLen + 1)
			{
				oFile << line << endl;
				line.clear();
			}

			line += word + ' ';
			word.clear();
		}
	}
}

#endif /* MYLIBRARY_H_ */
