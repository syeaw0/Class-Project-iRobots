// Admin.cpp

#include "Admin.h"

Admin::Admin() {
	initMenu();
	//customers.AddFromFile("CustomerList.txt");
}

void Admin::initMenu(){
	// Insertions
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintCustomersByName ), 	"Print Customers By Name");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintCustomers ), 			"Print Customers");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::SaveChanges ), 			"Save Changes");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::DeleteCustomer ), 			"Delete Customer");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::AddCustomer ), 			"Add Customer");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::CustomerSearch ), 			"Customer Search");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::ChangeCustomerInfo ), 		"Change Customer Info");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::Help ), 					"Help");

}

void Admin::Help(){
	printf("--Admin Class Help!\n");

}
void Admin::ChangeCustomerInfo(){
	printf("--Change Customer Info\n");
}
void Admin::CustomerSearch(){
	printf("--Customer Search\n");
}
void Admin::AddCustomer(){
	printf("--Add Customer\n");

	CustomerType	 aCust;
	char ans;
	do
	{
		customers.AddFromConsole();

		cout << "Add another? (y/n): ";
		cin.get(ans);
		ans = toupper(ans);
		cin.ignore(1000, '\n');

		customers.PrintList();
	}while(ans != 'N');

	// cin customers?
}
void Admin::DeleteCustomer(){
	printf("--Delete\n");

}
void Admin::SaveChanges(){
	printf("--Saving\n");

	customers.SaveList("TestSave.txt");
	// customer.save
}
void Admin::PrintCustomers(){
	printf("--Printing\n");
	customers.PrintAllCustomerList();

	// customers.printAll()
}
void Admin::PrintCustomersByName(){
	printf("--PrintByName\n");
	std::string inName = input::scanName();
	customers.CustomerSearch(inName);
	// customers.lookup(inName);
}
