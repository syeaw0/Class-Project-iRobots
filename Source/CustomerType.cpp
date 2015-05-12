/*
 * CustomerType.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: Jinko
 */

#include "CustomerType.h"

/**************************************************************************
 * CONSTRUCTOR default
 *************************************************************************/
CustomerType::CustomerType() {
	name.clear();
	address.clear();
	city.clear();
	state.clear();
	zipCode		 = 0;
	interestLvl  = VERY;
	desirability = KEY;
	received     = true;
}

/**************************************************************************
 * CONSTRUCTOR with parameters
 *************************************************************************/
CustomerType::CustomerType(string    aName,		// IN & CALC - Name
						   string    anAddress, // IN & CALC - Address
						   string    aCity,		// IN & CALC - City
						   string    aState,	// IN & CALC - State
						   int 	     aZipCode,	// IN & CALC - Zip code
						   Interest  aLevel,	// IN & CALC - Interest lvl
						   Desirable aRank,		// IN & CALC - Importance
						   bool 	 didReceive)// IN & CALC - Got pamphlet
{
	name 		 = aName;
	address 	 = anAddress;
	city 		 = aCity;
	state 		 = aState;
	zipCode 	 = aZipCode;
	interestLvl  = aLevel;
	desirability = aRank;
	received 	 = didReceive;
}

/**************************************************************************
 * CONSTRUCTOR with parameters
 *************************************************************************/
CustomerType::CustomerType(const CustomerType *otherCust)
{
	name 		 = otherCust->GetName();
	address 	 = otherCust->GetAddress();
	city 		 = otherCust->GetCity();
	state 		 = otherCust->GetState();
	zipCode      = otherCust->GetZipCode();
	interestLvl  = otherCust->GetInterestLevel();
	desirability = otherCust->GetDesirability();
	received     = otherCust->GetReceived();
}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
CustomerType::~CustomerType() {
	// TODO Auto-generated destructor stub
}

/**************************************************************************
 * 							MUTATORS
 * ------------------------------------------------------------------------
 * 						operator >>
 * 						operator <<
 * 						operator ==
 * 						operator !=
 * 						SetValues
 * 						SetName
 * 						SetAddress
 * 						SetCity
 * 						SetState
 * 						SetZipCode
 * 						SetInterestLevel
 * 						SetDesirability
 * 						SetReceived
 *************************************************************************/

/**************************************************************************
 * operator >>
 * 		This method overloads the >> operator. This will contain all
 * 		the information about a Customer. The >> operator will thus
 * 		get all input information about a Customer (name, address, city,
 * 		state, zip code, interest level, desirability, and whether
 * 		the Customer received a pamphlet.
 *
 * 		Return: aStream (>>)
 *************************************************************************/
istream& operator >> (istream&     inStream,	// IN, CALC & OUT - in Stream
					  CustomerType &aCustomer)  // IN & CALC	  - Customer
{
	// Variable List
	int  ratingNum;	// IN & CALC - Rating number for interest & desire
	char pamphlet;	// IN & CALC - Received pamphlet or not
	bool invalid;	// CALC		 - Invalid info

	// INPUT - Get Customer info: name, address, city, state
	cout << "Enter Name: ";
	getline(inStream, aCustomer.name);

	cout << "Enter Address: ";
	getline(inStream, aCustomer.address);

	cout << "Enter City: ";
	getline(inStream, aCustomer.city);

	cout << "Enter State: ";
	getline(inStream, aCustomer.state);

	// INPUT - Get Customer zip code and check validity - do until valid
	do
	{
		try
		{
			invalid = false;
			cout << "Enter Zip Code: ";
			if(!(inStream  >> aCustomer.zipCode))
			{
				inStream.clear();
				inStream.ignore(numeric_limits<streamsize>::max(), '\n');
				throw aCustomer.zipCode;
			}
			else if(aCustomer.zipCode < 0 || aCustomer.zipCode > 99999)
			{
				throw aCustomer.zipCode;
			}
		}

		// OUTPUT - Tell user if not valid zip code
		catch(int caughtZipCode)
		{
			invalid = true;
			cout << "Invalid zip code: " << caughtZipCode << endl;
		}
	}while(invalid);

	// PROCESSING - Get interest level & check if valid - do until valid
	do
	{
		try
		{
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
	}while(invalid);

	// PROCESSING - Get desire level until valid
	do
	{
		try
		{
			cout << "\niRobotsTheBomb desire to have Customer\n"
					"0 - Key Customer\n"
					"1 - Nice to Have Customer\n"
					"Enter Number: ";

			// INPUT - Get desire level
			if(!(inStream  >> ratingNum))
			{
				inStream.clear();
				inStream.ignore(numeric_limits<streamsize>::max(), '\n');
				throw ratingNum;
			}
			// PROCESSING - Check if menu choice is valid
			else if(ratingNum < 0 || ratingNum > 1)
			{
				throw ratingNum;
			}
			else
			{
				// PROCESSING - Get the correct desire level
				inStream.ignore(numeric_limits<streamsize>::max(), '\n');
				invalid = false;
				switch(ratingNum)
				{
					case 0	: 	aCustomer.desirability = KEY;
								break;
					case 1	: 	aCustomer.desirability = NICE_TO_HAVE;
								break;
					default	: 	break;
				}
			}
		}

		// OUTPUT - Tell user the desire level is not valid
		catch(int caughtDesireNum)
		{
			invalid = true;
			cout << "Invalid Desire level to have Customer: " << caughtDesireNum << endl;
		}

	}while(invalid);

	// PROCESSING - Get whether the pamphlet has been received - until valid
	do
	{
		try
		{
			// INPUT - Get received pamphlet or not (y/n)
			cout << "\nDid the Customer receive a pamphlet? (y/n): ";
			inStream.get(pamphlet);
			inStream.ignore(numeric_limits<streamsize>::max(), '\n');
			pamphlet = toupper(pamphlet);

			// PROCESSING - Check if invalid or not
			if(pamphlet != 'Y' && pamphlet != 'N')
			{
				throw pamphlet;
			}
			else
			{
				invalid = false;

				// PROCESSING - Get boolean if valid
				(pamphlet == 'Y')   ? aCustomer.received = true
									: aCustomer.received = false;
			}
		}

		// OUTPUT - Tell user if pamphlet is not valid
		catch(char caughtReceived)
		{
			invalid = true;
			cout << "Invalid information if pamphlet was received: " << caughtReceived << endl;
		}
	}while(invalid);

	return inStream;
}

/**************************************************************************
 * operator <<
 * 		This method overloads the << operator. This will contain all
 * 		the information about a Customer. The << operator will thus
 * 		output all information about a Customer (name, address, city,
 * 		state, zip code, interest level, desirability, and whether
 * 		the Customer received a pamphlet.
 *
 * 		Return: aStream (<<)
 *************************************************************************/
ostream& operator << (ostream      &outStream,	// IN, CALC & OUT - out stream
					  CustomerType &aCustomer)  // IN & CALC 	  - Customer
{
	// Variable List
	string anInterest;	// CALC & OUT - Interest level
	string aDesire;		// CALC & OUT - Desire level
	string pamphlet;	// CALC & OUT - Received pamphlet

	// OUTPUT - Displays Customer address info
	outStream << left			   << setfill(' ')
			  << setw(NAME_COL)    << aCustomer.name    << " "
			  << setw(ADDRESS_COL) << aCustomer.address << " "
			  << setw(CITY_COL)    << aCustomer.city    << " "
			  << setw(STATE_COL)   << aCustomer.state   << " "
			  << right			   << setfill('0')
			  << setw(ZIPCODE_COL) << aCustomer.zipCode << " ";

	// PROCESSING - Get interest level to output
	switch(aCustomer.interestLvl)
	{
		case VERY		: anInterest = "very interested";
						  break;
		case SOMEWHAT 	: anInterest = "somewhat interested";
						  break;
		case NO		  	: anInterest = "not interested";
						  break;
		case NEVER_CALL : anInterest = "never call";
						  break;
		default			: break;
	}

	// PROCESSING - Get desire level to output
	switch(aCustomer.desirability)
	{
		case KEY		  : aDesire = "key";
							break;
		case NICE_TO_HAVE : aDesire = "nice to have";
							break;
		default 		  :	break;
	}

	// PROCESSING - Get info if pamphlet  has been received info
	(aCustomer.received == true) ? pamphlet = "Received"
					   	   	   	 : pamphlet = "Not Received";

	// OUTPUT - Displays customer's interest, desire & pamphlet info
	outStream << left 		 	    << setfill(' ')
			  << setw(INTEREST_COL) << anInterest << " "
			  << setw(DESIRE_COL)   << aDesire    << " "
			  << setw(PAMPHLET_COL) << pamphlet   << endl;
	outStream << right;

	return outStream;
}

/**************************************************************************
 * operator ==
 * 		This method overloads the == operator and checks whether
 * 		the name of one Customer is the same as another Customer.
 *
 * 		Return: bool
 *************************************************************************/
bool CustomerType::operator ==(const CustomerType &otherCust) const
{
	// Variable List
	bool equal;		// CALC & OUT - Check if names are equal

	// PROCESSING - Check if names are the same
	(name == otherCust.name) ? equal = true
							 : equal = false;

	return equal;
}

/**************************************************************************
 * operator !=
 * 		This method overloads the != operator and checks whether
 * 		the name of one Customer is not the same as another Customer.
 *
 * 		Return: bool
 *************************************************************************/
bool CustomerType::operator !=(const CustomerType &otherCust) const
{
	// Variable List
	bool unequal;	// CALC & OUT - Check if names are not equal

	// PROCESSING - Check if names are not the same
	(name != otherCust.name) ? unequal = true
							 : unequal = false;

	return unequal;
}

/**************************************************************************
 * operator >
 * 		This method overloads the > operator. This method is to help check
 * 		whether or not one name is greater than the other (helps to insert
 * 		names in order).
 *
 * 		Return: isGreater (bool)
 *************************************************************************/
bool CustomerType::operator >(const CustomerType &otherCust) const
{
	// Variable List
	bool isGreater;		// CALC & OUT - If greater than

	// PROCESSING - Check if greater than
	(name > otherCust.name) ? isGreater = true
							: isGreater = false;

	return isGreater;
}

/**************************************************************************
 * operator >
 * 		This method overloads the < operator. This method is to help check
 * 		whether or not one name is less than the other (helps to insert
 * 		names in order).
 *
 * 		Return: isLess (bool)
 *************************************************************************/
bool CustomerType::operator <(const CustomerType &otherCust) const
{
	// Variable List
	bool isLess;		// CALC & OUT - If less than

	// PROCESSING - Check if less than
	(name < otherCust.name) ? isLess = true
							: isLess = false;

	return isLess;
}

/**************************************************************************
 * SetValues
 * 		This method sets all the values for a Customer. This includes
 * 		the customer's name, address, city, state, zipcode, the customer's
 * 		interest level in the company, the company's desire to have the
 * 		customer, and whether or not the customer received the pamphlet.
 *
 * 		Return: nothing (Set all values to Customer)
 *************************************************************************/
void CustomerType::SetValues(string    aName,	  // IN & CALC - Name
						     string    anAddress, // IN & CALC - Address
						     string    aCity,	  // IN & CALC - City
						     string    aState,	  // IN & CALC - State
						     int 	   aZipCode,  // IN & CALC - Zip code
						     Interest  aLevel,	  // IN & CALC - Interest lvl
						     Desirable aRank,	  // IN & CALC - Importance
						     bool 	   didReceive)// IN & CALC - Got pamphlet
{
	name 		 = aName;
	address 	 = anAddress;
	city 		 = aCity;
	state 		 = aState;
	zipCode 	 = aZipCode;
	interestLvl  = aLevel;
	desirability = aRank;
	received 	 = didReceive;
}

/**************************************************************************
 * SetName
 * 		This method sets the name of the Customer.
 *
 * 		Return: nothing (Sets name)
 *************************************************************************/
void CustomerType::SetName(string aName)	// IN & CALC - Name
{
	name = aName;
}

/**************************************************************************
 * SetAddress
 * 		This method sets the Customer's address.
 *
 * 		Return: nothing (Sets address)
 *************************************************************************/
void CustomerType::SetAddress(string anAddress)	// IN & CALC - Address
{
	address = anAddress;
}

/**************************************************************************
 * SetCity
 * 		This method sets the Customer's city.
 *
 * 		Return: nothing (Sets city)
 *************************************************************************/
void CustomerType::SetCity(string aCity)	// IN & CALC - City
{
	city = aCity;
}

/**************************************************************************
 * SetState
 * 		This method sets the Customer's state.
 *
 * 		Return: nothing (Sets state)
 *************************************************************************/
void CustomerType::SetState(string aState)	// IN & CALC - State
{
	state = aState;
}

/**************************************************************************
 * SetZipCode
 * 		This method sets the Customer's zipcode.
 *
 * 		Return: nothing (Sets zipCode)
 *************************************************************************/
void CustomerType::SetZipCode(int aZipCode)	// IN & CALC - Zipcode
{
	zipCode = aZipCode;
}

/**************************************************************************
 * SetInterestLevel
 * 		This method sets the Customer's interest level in the company.
 *
 * 		Return: nothing (Sets interestLvl)
 *************************************************************************/
void CustomerType::SetInterestLevel(Interest aLevel) // IN & CALC - Interest
{
	interestLvl = aLevel;
}

/**************************************************************************
 * SetDesirability
 * 		This method sets the company's desire to have the Customer.
 *
 * 		Return: nothing (Sets desirability)
 *************************************************************************/
void CustomerType::SetDesirability(Desirable aDesire) // IN & CALC - Desire
{
	desirability = aDesire;
}

/**************************************************************************
 * SetReceived
 * 		This method sets whether the Customer has received the pamphlet.
 *
 * 		Return: nothing (Sets received)
 *************************************************************************/
void CustomerType::SetReceived(bool isReceived) // IN & CALC - Desire
{
	received = isReceived;
}

/**************************************************************************
 * 							ACCESSORS
 * ------------------------------------------------------------------------
 * 						CheckName
 * 						GetName
 * 						GetAddress
 * 						GetCity
 * 						GetState
 * 						GetZipCode
 * 						GetInterestLevel
 * 						GetDesirability
 * 						GetReceived
 * 						Print
 *************************************************************************/

/**************************************************************************
 * CheckName
 * 		This method checks if the name is the same as the
 * 		name of the Customer.
 *
 * 		Return: equal (bool)
 *************************************************************************/
bool CustomerType::CheckName(string aName) const
{
	bool equal;

	(name == aName) ? equal = true
					: equal = false;

	return equal;
}

/**************************************************************************
 * GetName
 * 		This method gets the Customer's name.
 *
 * 		Return: name (string)
 *************************************************************************/
string CustomerType::GetName() const
{
	return name;
}

/**************************************************************************
 * GetAddress
 * 		This method gets the Customer's address.
 *
 * 		Return: address (string)
 *************************************************************************/
string CustomerType::GetAddress() const
{
	return address;
}

/**************************************************************************
 * GetCity
 * 		This method gets the Customer's city.
 *
 * 		Return: city (string)
 *************************************************************************/
string CustomerType::GetCity() const
{
	return city;
}

/**************************************************************************
 * GetState
 * 		This method gets the Customer's state.
 *
 * 		Return: state (string)
 *************************************************************************/
string CustomerType::GetState() const
{
	return state;
}

/**************************************************************************
 * GetZipCode
 * 		This method gets the Customer's zipcode.
 *
 * 		Return: zipCode (string)
 *************************************************************************/
int CustomerType::GetZipCode() const
{
	return zipCode;
}

/**************************************************************************
 * GetInterstLevel
 * 		This method gets the Customer's interest level in company.
 *
 * 		Return: interestLvl (Interest)
 *************************************************************************/
Interest CustomerType::GetInterestLevel() const
{
	return interestLvl;
}

/**************************************************************************
 * GetDesirability
 * 		This method gets the company's desire in Customer.
 *
 * 		Return: desirability (Desirable)
 *************************************************************************/
Desirable CustomerType::GetDesirability() const
{
	return desirability;
}

/**************************************************************************
 * GetReceived
 * 		This method gets whether Customer has received the pamphlet.
 *
 * 		Return: received (bool)
 *************************************************************************/
bool CustomerType::GetReceived() const
{
	return received;
}

/**************************************************************************
 * Print
 * 		This method prints out all the information about a Customer.
 *
 * 		Return: nothing (Prints Customer info)
 *************************************************************************/
void CustomerType::Print() const
{
	// Variable List
	string anInterest;	// CALC & OUT - Interest level
	string aDesire;		// CALC & OUT - Desire level
	string pamphlet;	// CALC & OUT - Received pamphlet

	// OUTPUT - Displays Customer address info
	cout << left;
	cout << setw(NAME_COL)    << name    << " "
		 << setw(ADDRESS_COL) << address << " "
		 << setw(CITY_COL)    << city    << " "
		 << setw(STATE_COL)   << state   << " "
		 << setw(ZIPCODE_COL) << zipCode << " ";

	// PROCESSING - Get interest level to output
	switch(interestLvl)
	{
		case VERY		: anInterest = "very interested";
						  break;
		case SOMEWHAT 	: anInterest = "somewhat interested";
						  break;
		case NO		  	: anInterest = "not interested";
						  break;
		case NEVER_CALL : anInterest = "never call";
						  break;
		default			: break;
	}

	// PROCESSING - Get desire level to output
	switch(desirability)
	{
		case KEY		  : aDesire = "key";
							break;
		case NICE_TO_HAVE : aDesire = "nice to have";
							break;
		default 		  :	break;
	}

	// PROCESSING - Get info if pamphlet  has been received info
	(received == true) ? pamphlet = "Received"
					   : pamphlet = "Not Received";

	// OUTPUT - Displays customer's interest, desire & pamphlet info
	cout << setw(INTEREST_COL) << anInterest << " "
		 << setw(DESIRE_COL)   << aDesire    << " "
		 << setw(PAMPHLET_COL) << pamphlet   << endl;
	cout << right;
}
