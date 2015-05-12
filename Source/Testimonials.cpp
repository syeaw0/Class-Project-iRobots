/*
 * Testimonials.cpp
 *
 *  Created on: May 11, 2015
 *      Author: jinko
 */

#include "Testimonials.h"

Testimonials::Testimonials() {
	aTest.aRating = FIVE_STARS;
	aTest.custName.clear();
	aTest.words.clear();
}

Testimonials::~Testimonials() {
	// TODO Auto-generated destructor stub
}

void Testimonials::AddTestimonial(string fileName)
{
	int stars;
	ofstream outFile;

	aTest.custName = input::scanString("Enter Name: ");
	stars = input::scanIntPrompt("Rate Stars\n"
			"0 - Zero Star\n"
			"1 - One Star\n"
			"2 - Two Stars\n"
			"3 - Three Stars\n"
			"4 - Four Stars\n"
			"5 - Five Stars\n"
			"Enter: ", "***Invalid Rating***", 0, 5);

	switch(stars)
	{
	case 0  :	aTest.aRating = ZERO_STARS;
				break;
	case 1  : 	aTest.aRating = ONE_STARS;
				break;
	case 2  : 	aTest.aRating = TWO_STARS;
				break;
	case 3  :	aTest.aRating = THREE_STARS;
				break;
	case 4  : 	aTest.aRating = FOUR_STARS;
				break;
	case 5  : 	aTest.aRating = FIVE_STARS;
				break;
	default :	break;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	aTest.words = input::scanString("Enter Testimonial: ");

	cout << aTest.words << endl;
	testList.push_back(aTest);
	SaveTestimonial(fileName);
}

void Testimonials::AddFromFile(string fileName)
{
	ifstream inFile;
	string rating;

	inFile.open(fileName.c_str());

	if(inFile.fail())
	{
		cout << "File does not exist\n";
	}
	else
	{
		while(!inFile.eof())
		{
			getline(inFile, aTest.custName);
			if(aTest.custName != "")
			{
				getline(inFile, rating);
				getline(inFile, aTest.words);
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');

				(rating == "Zero Stars") ? aTest.aRating = ZERO_STARS
						: (rating == "One Stars") ? aTest.aRating = ONE_STARS
								: (rating == "Two Stars") ? aTest.aRating = TWO_STARS
										: (rating == "Three Stars") ? aTest.aRating = THREE_STARS
												: (rating == "Four Stars") ? aTest.aRating = FOUR_STARS
														: (rating == "Five Stars") ? aTest.aRating = FIVE_STARS
																: aTest.aRating = FIVE_STARS;

				testList.push_back(aTest);
			}
		}
	}
	inFile.close();
}

void Testimonials::SaveTestimonial(string fileName)
{
	int count;
	ofstream outFile;

	count = signed(testList.size());
	outFile.open(fileName.c_str(), std::ios_base::app);

	if(outFile.fail())
	{
		cout << "File does not exist\n";
	}
	else
	{
		outFile << aTest.custName;
		outFile << endl;

		switch(aTest.aRating)
		{
		case ZERO_STARS  : 	outFile << "Zero Stars\n";
							break;
		case ONE_STARS   : 	outFile << "One Stars\n";
							break;
		case TWO_STARS   : 	outFile << "Two Stars\n";
							break;
		case THREE_STARS : 	outFile << "Three Stars\n";
							break;
		case FOUR_STARS  : 	outFile << "Four Stars\n";
							break;
		case FIVE_STARS  : 	outFile << "Five Stars\n";
							break;
		default 		 : 	break;

		}
		outFile << aTest.words;
		outFile << endl << endl;
	}
}

void Testimonials::Print() const
{
	const int MAX_LENGTH = 75;
	int count;
	int size;
	string   wordOut;	// CALC & OUT - One word from synopsis
	string   lineOut;	// CALC & OUT - A line from synopsis
	int 	 index;		// CALC		  - Index synopsis string
	int 	 strLength;	// CALC		  - Length of synopsis

	size = signed(testList.size());

	for(count = 0; count < size; count++)
	{
		if(testList[count].aRating == FOUR_STARS ||
		   testList[count].aRating == FIVE_STARS)
		{

			// PROCESSING - Length of synopsis
			strLength = testList[count].words.length();

			// PROCESSING - Initialize line and word to none
			lineOut = "";
			wordOut = "";

			// PROCESSING - Index through all of synopsis
			for(index = 0; index < strLength; index++)
			{
				// PROCESSING - Check for spaces
				if(testList[count].words[index] != ' ')
				{
					wordOut += testList[count].words[index];
				}
				else
				{
					// PROCESSING - Check for length of line / clear line
					if((lineOut.length() + wordOut.length()) > MAX_LENGTH)
					{
						// OUTPUT - A line from synopsis
						cout << lineOut;
						cout << endl;
						lineOut.clear();
					}

					// OUTPUT - A word from synopsis plus space / clear word
					lineOut += wordOut + ' ';
					wordOut.clear();
				}
			}
			// OUTPUT - A line from synopsis / clear line
			cout << lineOut;

			// OUTPUT - Check if word fits on line or not / clear word
			if(lineOut.length() + wordOut.length() > MAX_LENGTH)
			{
				cout << endl;
			}

			// OUTPUT - Word that did not fit on last line
			cout << wordOut;

			// PROCESSING - Clear the line and word
			lineOut.clear();
			wordOut.clear();
		}
		cout << "\n     - " << testList[count].custName << endl << endl;
	}
}

void Testimonials::ClearTestimonials()
{
	testList.clear();
}

void Testimonials::SolicitForTestimonial()
{
	char ans;

	ans = input::scanChar("Do you want to add a testimonial (Y/N)? ", "***Invalid Response***", 'Y', 'N');

	if(ans == 'Y')
	{
		AddTestimonial("TestimonialsInfo.txt");
	}

}
