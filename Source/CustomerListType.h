
#ifndef CUSTOMERLISTTYPE_H_
#define CUSTOMERLISTTYPE_H_

#include "DoublyLinkedList.h"
#include "CustomerType.h"
#include "input.h"
#include <string>
#include <fstream>

class CustomerListType : public DoublyLinkedList<CustomerType>{
public:
	/********************************
	 ****CONSTRUCTOR & DESTRUCTOR****
	 ********************************/
	CustomerListType();					// Default Constructor
	virtual ~CustomerListType();		// Destructor

	/****************
	 ****MUTATORS****
	 ****************/
	void AddFromConsole();				// Add Customer From Console
	void AddFromFileGuestToCust(string fileName);
	void AddFromFile(string fileName);	// Add Customers From File
	void ChangeCustomerInfo(string aName);
	bool DeleteACustomer(string aName);	// Delete a Customer
	void SaveAndOpenList(string fileName);

	/*****************
	 ****ACCESSORS****
	 *****************/
	bool CustomerSearch(string aName) const;	// Search for Customer
	void PrintAllCustomerList() const;			// Print All Customers
	void PrintKeyCustomerList() const;			// Print Key Customers
	void SaveList(string fileName) const;		// Save Customer List

private:
	/*****************
	 ****ACCESSORS****
	 *****************/
	void SearchCustomerList(string 				aName,	// Search
							bool				&found,
							Node<CustomerType>*	&current) const;
};

#endif /* CUSTOMERLISTTYPE_H_ */
