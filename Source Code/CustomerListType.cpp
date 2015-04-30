
#include "CustomerListType.h"

/**************************************************************************
 * CONSTRUCTOR
 *************************************************************************/
CustomerListType::CustomerListType() {		}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
CustomerListType::~CustomerListType() {		}

/**************************************************************************
 * 							MUTATORS
 * ------------------------------------------------------------------------
 * 						AddFromConsole
 * 						AddFromFile
 * 						DeleteAllCustomer
 *************************************************************************/

/**************************************************************************
 * AddFromConsole
 * 		This method adds a Customer to the CustomerList from the console.
 * 		This method will get the following information: name,
 * 		address, city, state, zip code, whether the customer is
 * 		interested in the company, and the company's desire to have
 * 		this customer as a customer.
 *
 * 		Return: nothing (Adds customer to the list)
 *************************************************************************/
void CustomerListType::AddFromConsole()
{
	// Variable List
	Node<CustomerType> *currPtr;	// CALC		 - Customer Node
	CustomerType 		newNode;	// IN & CALC - Customer to add
	bool		 		found;		// CALC		 - Found Customer

	currPtr   = NULL;

	// INPUT - Get input about the Customer
	cin >> newNode;

	try
	{
		// PROCESSING - Search if the customer already exists
		SearchCustomerList(newNode.GetName(), found, currPtr);

		// PROCESSING - If Customer Exists throw
		if(found == true)
		{
			throw newNode.GetName();
		}
	}

	// OUTPUT - Tell user that this Customer already exists
	catch(string &caughtName)
	{
		cout << "Sorry this customer already exists: "
			 << newNode.GetName() << endl;
	}

	// PROCESSING - Add to the Customer list if name is unique
	if(!found)
	{
		AddNode(newNode);
	}
	else
	{
		cout << "Sorry this Customer could not be added\n";
	}
}

/**************************************************************************
 * AddFromFile
 * 		This method adds Customers from a file to the Customer list.
 * 		The following information about a customer will be needed from
 * 		the file: the name, address, city, state, zip code, how interested
 * 		the customer is in the company, and how much the company desires
 * 		to have this customer as a customer.
 *
 * 		Return: nothing (Adds customer to the list)
 *************************************************************************/
void CustomerListType::AddFromFile(string fileName) // IN & CALC - File
{
	// Variable List
	Node<CustomerType> *currPtr;
	CustomerType newNode;		// CALC - Customer to add
	string       addName;		// IN & CALC - Customer's name
	string    	 addAddress;	// IN & CALC - Customer's address
	string    	 addCity;		// IN & CALC - Customer's city
	string    	 addState;		// IN & CALC - Customer's state
	int 	  	 addZipCode;	// IN & CALC - Customer's zip code
	string 	  	 anInterest;	// IN & CALC - Customer's interest
	string 	  	 aDesire;		// IN & CALC - Company desire in customer
	Interest  	 addInterest;	// CALC		 - Customer's interest
	Desirable 	 addDesire;		// CALC		 - Company desire in customer
	ifstream	 inFile;		// CALC		 - File input stream
	bool		 validName;		// CALC		 - Valid input name
	bool		 validDesire;	// CALC		 - Valid desire level
	bool		 validInterest;	// CALC		 - Valid interest level
	bool		 validZipCode;	// CALC		 - Valid zip code

	inFile.open(fileName.c_str());

	// PROCESSING - Check if file exists or not
	if(!inFile)
	{
		cout << "Sorry, this file does not exist!\n";
	}
	else
	{
		// PROCESSING - Keep looping until end of file
		while(!inFile.eof())
		{
			currPtr		  = NULL;
			validName 	  = false;
			validDesire   = false;
			validInterest = false;
			validZipCode  = false;

			// INPUT - Get name
			try
			{
				// PROCESSING - Get name & search the list to see if unique
				getline(inFile, addName);
				SearchCustomerList(addName, validName, currPtr);

				// PROCESSING - Throw if name is not unique
				if(validName)
				{
					throw addName;
				}
			}

			// OUTPUT - Tell user that this Customer alread exists
			catch(string &caughtName)
			{
				cout << "Sorry this Customer already exists: "
					 << caughtName << endl;
			}

			// INPUT - Get address, city, state
			getline(inFile, addAddress);
			getline(inFile, addCity, ',');
			inFile.ignore(1, '\n');
			getline(inFile, addState, ' ');

			// INPUT - Get zip code
			try
			{
				// PROCESSING - Check if valid zip code or throw if not
				if(!(inFile >> addZipCode))
				{
					inFile.clear();
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');
					throw addZipCode;
				}
				else if(addZipCode < 0 || addZipCode > 99999)
				{
					throw addZipCode;
				}
			}

			// OUTPUT - Tell user invalid zip code
			catch(int caughtZipCode)
			{
				validZipCode = false;
				cout << "Invalid zip code: " << caughtZipCode << endl;
			}

			// INPUT - Get desire level, interest level
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(inFile, anInterest);
			getline(inFile, aDesire);

			try
			{
				// PROCESSING - Get interest level
				if(anInterest == "very interested")
				{
					addInterest = VERY;
				}
				else if(anInterest == "somewhat interested")
				{
					addInterest = SOMEWHAT;
				}
				else if(anInterest == "not interested")
				{
					addInterest = NO;
				}
				else if(anInterest == "never call")
				{
					addInterest = NEVER_CALL;
				}
				else
				{
					throw anInterest;
				}
			}

			// OUTPUT - Tell user interest level is not valid
			catch(string &caughtInterest)
			{
				validInterest = false;
				cout << "Invalid interest level: " << caughtInterest << endl;
			}

			try
			{
				// PROCESSING - Get desire level
				(aDesire == "key") ? addDesire = KEY
								   : (aDesire == "nice to have")
								   ? addDesire = NICE_TO_HAVE
								   : throw aDesire;
			}

			// OUTPUT - Tell user if desire is not valid
			catch(string &aDesire)
			{
				validDesire = false;
				cout << "Invalid Company Desire level to have Customer: "
					 << aDesire << endl;
			}

			// PROCESSING - Add customer if valid input
			if(addName != "" && !validName && !validInterest &&
			   !validDesire && !validZipCode)
			{
				newNode.SetName(addName);
				newNode.SetAddress(addAddress);
				newNode.SetCity(addCity);
				newNode.SetState(addState);
				newNode.SetZipCode(addZipCode);
				newNode.SetInterestLevel(addInterest);
				newNode.SetDesirability(addDesire);
				newNode.SetReceived(true);

				// PROCESSING - Add Customer to list
				AddNode(newNode);
			} // END IF
		} // END WHILE
	} // END IF-ELSE

	inFile.close();
}

/**************************************************************************
 * DeleteACustomer
 * 		This method receives a name (string) that the user would like to
 * 		delete. This method will then loop and search through the list
 * 		until found or end of list. If the name is found then the Customer
 * 		will be deleted from the list. Otherwise the list will remain.
 *
 * 		Return: found (bool)
 *************************************************************************/
bool CustomerListType::DeleteACustomer(string aName) // IN - Name to delete
{
	// Variable List
	bool 				found;		// CALC & OUT - Deleted Customer
	Node<CustomerType> *toDelete;	// CALC 	  - Pointer to customer
	CustomerType		custInfo;	// CALC 	  - Customer info

	found = false;

	// PROCESSING - Call Search method to find customer
	SearchCustomerList(aName, found, toDelete);

	// PROCESSING - If found remove customer
	if(found)
	{
		custInfo = toDelete->data;
		RemoveNode(custInfo);
	}

	return found;
}

/**************************************************************************
 * 							ACCESSORS
 * ------------------------------------------------------------------------
 * 						CustomerSearch
 * 						PrintAllCustomerList
 * 						PrintKeyCustomerList
 * 						SaveList
 *************************************************************************/

/**************************************************************************
 * CustomerSearch
 * 		This method receives a name (string) that the user would like to
 * 		delete. This method will then loop and search through the list
 * 		until found or end of list. If the name is found then the Customer
 * 		will be deleted from the list. Otherwise the list will remain.
 *
 * 		Return: found (bool)
 *************************************************************************/
bool CustomerListType::CustomerSearch(string aName) const // IN - Find name
{
	// Variable List
	bool 				found;	// CALC & OUT - Found name
	Node<CustomerType> *toFind;	// CALC		  - Pointer to traverse list

	found = false;

	// PROCESSING - Find name in customer list
	SearchCustomerList(aName, found, toFind);

	// PROCESSING - If found display info or say customer does not exist
	if(found == true)
	{
		cout << "Found Customer:\n";
		toFind->data.Print();
		cout << endl;
	}
	else
	{
		cout << "Customer does not exist in system.\n";
	}
	return found;
}

/**************************************************************************
 * PrintAllCustomerList
 * 		This method prints all the customers in the customer list.
 * 		The following data includes: Name, address, city, state, zip code,
 * 		how interested the customer is in the company, how much the
 * 		company desires to have the customer, and whether or not the
 * 		pamphlet has been received.
 *
 * 		Return: nothing (Display list to console)
 *************************************************************************/
void CustomerListType::PrintAllCustomerList() const
{
	// Variable List
	Node<CustomerType> *tempNode; // CALC - Temp pointer in list

	tempNode = GetHead();

	// PROCESSING & OUTPUT - Loop through entire list & show customer info
	while(tempNode != NULL)
	{
		cout << tempNode->data;
		tempNode = tempNode->next;
	}

	cout << endl;
}

/**************************************************************************
 * PrintKeyCustomerList
 * 		This method prints all the key customers in the customer list.
 * 		The following data includes: Name, address, city, state, zip code,
 * 		how interested the customer is in the company, that the customer
 * 		is a key customer, & whether or not the pamphlet has been received.
 *
 * 		Return: nothing (Display list to console)
 *************************************************************************/
void CustomerListType::PrintKeyCustomerList() const
{
	// Variable List
	Node<CustomerType> *tempNode;	// CALC & OUT - Temp pointer to list

	tempNode = GetHead();

	// PROCESSING - Loops through entire list
	while(tempNode != NULL)
	{
		// PROCESSING - Check if Key customer & print info if so
		if(tempNode->data.GetDesirability() == KEY)
		{
			cout << tempNode->data;
		}

		tempNode = tempNode->next;
	}

	cout << endl;
}

/**************************************************************************
 * SaveList
 * 		This method saves the entire Customer list to a txt file.
 * 		The name of the file will be passed in. The following information
 * 		about a Customer will be saved to the file: name, address,
 * 		city, state, zip code, interest level in company, and company's
 * 		desire to have customer as a customer.
 *
 * 		Return: nothing (Saves customer to a txt file)
 *************************************************************************/
void CustomerListType::SaveList(string fileName) const
{
	// Variable List
	ofstream 			outFile;	// CALC - Output file stream
	Node<CustomerType> *tempNode;	// CALC & OUT - Temp ptr to list
	string 				anInterest;	// CALC & OUT - Interest level in co.
	string 				aDesire;	// CALC & OUT - Desire (key cust or not)

	tempNode = GetHead();

	outFile.open(fileName.c_str());

	// PROCESSING - Traverse through list until end
	while(tempNode != NULL)
	{
		// OUTPUT - Add information about customer to file (name,
		//		  - address, city, state, and zip code
		outFile << tempNode->data.GetName()    << endl
				<< tempNode->data.GetAddress() << endl
		 	 	<< tempNode->data.GetCity()    << ", "
				<< tempNode->data.GetState()   << " "
				<< tempNode->data.GetZipCode() << endl;

		// PROCESSING - Get interest level to output
		switch(tempNode->data.GetInterestLevel())
		{
			case VERY		: anInterest = "Very";
							  break;
			case SOMEWHAT 	: anInterest = "Somewhat";
							  break;
			case NO		  	: anInterest = "No";
							  break;
			case NEVER_CALL : anInterest = "Never Call";
							  break;
			default			: break;
		}

		// PROCESSING - Get desire level to output
		switch(tempNode->data.GetDesirability())
		{
			case KEY		  : aDesire = "Key";
								break;
			case NICE_TO_HAVE : aDesire = "Nice To Have";
								break;
			default 		  :	break;
		}

		// OUTPUT - Add customer's interest level & company's desire
		//		  - to have customer to output file
		outFile << anInterest << endl
				<< aDesire    << endl;

		// PROCESSING - Get next customer in list
		tempNode = tempNode->next;
	}

	outFile.close();
}

/**************************************************************************
 * SearchCustomerList (PRIVATE METHOD)
 * 		This method receives a name (string), a boolean of whether or not
 * 		the customer is found, and the customer node (info). The customer
 * 		node and whether the customer is found will be passed back. This
 * 		method will check each member in the list until found or end of
 * 		the list.
 *
 * 		Return: found (bool) and currPtr (Node<CustoemrType>) (by ref)
 *************************************************************************/
void CustomerListType::SearchCustomerList(string 			  aName,
										  bool				  &found,
										  Node<CustomerType>* &currPtr) const
{
	// PROCESSING - Set variables
	found   = false;
	currPtr = GetHead();

	// PROCESSING - Keep looping through list until found or end of list
	while(currPtr != NULL && !found)
	{
		// PROCESSING - Check if name is the same else go to next in list
		if(currPtr->data.CheckName(aName))
		{
			found = true;
		}
		else
		{
			currPtr = currPtr->next;
		}
	}
}
