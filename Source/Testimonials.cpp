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
	int index;
	int count;
	ofstream outFile;

	count = signed(testList.size());
	outFile.open(fileName.c_str());

	if(outFile.fail())
	{
		cout << "File does not exist\n";
	}
	else
	{
		for(index = 0; index < count; index++)
		{
			outFile << testList[index].custName;
			outFile << endl;

			switch(testList[index].aRating)
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
			outFile << testList[index].words;
			outFile << endl << endl;

		}
	}
}

void Testimonials::Print() const
{
	int index;
	int size;

	size = signed(testList.size());

	for(index = 1; index < size; index++)
	{
		if(testList[index].aRating == FOUR_STARS ||
		   testList[index].aRating == FIVE_STARS)
		{
			cout << testList[index].words << endl;
			cout << "     - " << testList[index].custName << endl;
		}
	}
}




