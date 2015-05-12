/*
 * Testimonials.h
 *
 *  Created on: May 11, 2015
 *      Author: jinko
 */

#ifndef TESTIMONIALS_H_
#define TESTIMONIALS_H_

#include <vector>
#include "input.h"
#include <fstream>
#include <string>
using namespace std;

enum RatingTest
{
	ZERO_STARS,
	ONE_STARS,
	TWO_STARS,
	THREE_STARS,
	FOUR_STARS,
	FIVE_STARS
};

struct TestInfo
{
	string custName;
	RatingTest	aRating;
	string words;
};

class Testimonials {
public:
	Testimonials();
	virtual ~Testimonials();

	void AddTestimonial(string fileName);
	void AddFromFile(string fileName);
	void SaveTestimonial(string fileName);
	void Print() const;

private:
	TestInfo aTest;
	vector<TestInfo> testList;
};

#endif /* TESTIMONIALS_H_ */
