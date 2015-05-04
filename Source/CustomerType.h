
#ifndef CUSTOMERTYPE_H_
#define CUSTOMERTYPE_H_

#include <iostream>
#include <iomanip>
#include <ios>
#include <limits>
using namespace std;

/**************************************************************************
 * GLOBAL CONSTANTS
 * ------------------------------------------------------------------------
 * NAME_COL		: Format for printing name
 * ADDRESS_COL	: Format for printing address
 * CITY_COL		: Format for printing city
 * STATE_COL	: Format for printing state
 * ZIPCODE_COL	: Format for printing zipcode
 * INTEREST_COL	: Format for printing customer's interest level
 * DESIRE_COL	: Format for printing company's desire to have customer
 * PAMPHLET_COL	: Format for printing a received pamphlet
 *************************************************************************/
const int NAME_COL     = 20;
const int ADDRESS_COL  = 25;
const int CITY_COL     = 15;
const int STATE_COL    = 10;
const int ZIPCODE_COL  = 5;
const int INTEREST_COL = 10;
const int DESIRE_COL   = 12;
const int PAMPHLET_COL = 12;

// Interest: The Customer's interest level in company
enum Interest
{
	VERY,
	SOMEWHAT,
	NO,
	NEVER_CALL
};

// Desirable: The Company's desire to have the Customer
enum Desirable
{
	KEY,
	NICE_TO_HAVE
};

class CustomerType {
public:
	/********************************
	 ****CONSTRUCTOR & DESTRUCTOR****
	 ********************************/
	CustomerType();								// Default Constructor
	CustomerType(string    aName,				// Constructor w/ parameters
				 string    anAddress,
				 string    aCity,
				 string    aState,
				 int 	   aZipCode,
				 Interest  aLevel,
				 Desirable aRank,
				 bool 	   didReceive);
	CustomerType(const CustomerType *otherCust);// Copy constructor
	virtual ~CustomerType();					// Destructor

	/****************
	 ****MUTATORS****
	 ****************/
	// Overloaded operators >>, <<, ==, !=, >, <
	friend istream& operator >> (istream& aStream, CustomerType &aCustomer);
	friend ostream& operator << (ostream &aStream, CustomerType &aCustomer);
	bool operator==(const CustomerType &otherCust) const;
	bool operator!=(const CustomerType &otherCust) const;
	bool operator>(const CustomerType &otherCust) const;
	bool operator<(const CustomerType &otherCust) const;

	void SetValues(string    aName,			// Set all Customer info
				   string    anAddress,
				   string    aCity,
				   string    aState,
				   int 	     aZipCode,
				   Interest  aLevel,
				   Desirable aRank,
				   bool 	 didReceive);
	void SetName(string aName);				// Set Customer name
	void SetAddress(string anAddress);		// Set Customer address
	void SetCity(string aCity);				// Set Customer city
	void SetState(string aState);			// Set Customer state
	void SetZipCode(int aZipCode);			// Set Customer zipcode
	void SetInterestLevel(Interest aLevel);	// Set Customer interest level
	void SetDesirability(Desirable aDesire);// Set company's desire in Cust
	void SetReceived(bool isReceived);		// Set received company pamphlet

	/*****************
	 ****ACCESSORS****
	 *****************/
	bool	  CheckName(string aName) const;// Check if Names are same
	string    GetName() const;				// Get Customer name
	string    GetAddress() const;			// Get Customer address
	string    GetCity() const;				// Get Customer city
	string    GetState() const;				// Get Customer state
	int       GetZipCode() const;			// Get Customer zip code
	Interest  GetInterestLevel() const;		// Get Customer interest level
	Desirable GetDesirability() const;		// Get company's desire in Cust.
	bool      GetReceived() const;			// Get if pamphlet is received
	void      Print() const;				// Print all Customer info

private:
	string    name;				// Customer name
	string    address;			// Customer address
	string    city;				// Customer city
	string    state;			// Customer state
	int		  zipCode;			// Customer zip code
	Interest  interestLvl;		// Customer Interest level in company
	Desirable desirability;		// Company's desire to have customer
	bool	  received;			// Customer received pamphlet
};

#endif /* CUSTOMERTYPE_H_ */
