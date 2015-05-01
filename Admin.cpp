// Admin.cpp

#include "Admin.h"

Admin::Admin() {
	initMenu();
	//customers.AddFromFile("CustomerList.txt");
}

void Admin::initMenu(){

	// Additions, the menu ends up in an ugly order
	//addOption(static_cast<Pamphlet::fptr>( &Admin::Help ), 					"Help");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::ChangeCustomerInfo ), 	"Change Customer Info");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::CustomerSearch ), 		"Customer Search");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::AddCustomer ), 			"Add Customer");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::DeleteCustomer ), 		"Delete Customer");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::SaveChanges ), 			"Save Changes");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::PrintCustomers ), 		"Print Customers");
	//addOption(static_cast<Pamphlet::fptr>( &Admin::PrintCustomersByName ), 	"Print Customers By Name");

	// Insertions instead
	insertOption(static_cast<Pamphlet::fptr>( &Admin::PrintCustomersByName ),  "Print Customers By Name");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::PrintCustomers ), 		"Print Customers");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::SaveChanges ), 			"Save Changes");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::DeleteCustomer ), 		"Delete Customer");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::AddCustomer ), 			"Add Customer");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::CustomerSearch ), 		"Customer Search");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::ChangeCustomerInfo ), 	"Change Customer Info");
	insertOption(static_cast<Pamphlet::fptr>( &Admin::Help ), 					"Help");

	// Alternatively w/ public menu
	//		menu.insert(menu.begin(), menuOption(static_cast<Pamphlet::fptr>( &Admin::Help ), "Help"));
	//			OR
	//		menu.push_back(menuOption(static_cast<Pamphlet::fptr>( &Admin::Help ), 			"Help");
}

void Admin::Help(){
	printf("--Help You!\n");
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
	std::string inName = scanName();
	customers.CustomerSearch(inName);
	// customers.lookup(inName);
}
