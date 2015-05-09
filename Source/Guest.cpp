// Guest.cpp

#include "Guest.h"


Guest::Guest() {
	initMenu();
}
void Guest::initMenu(){
	menu.insert(static_cast<Pamphlet::fptr>( &Guest::RequestPamphlet ),	"Request Pamphlet");
	menu.insert(static_cast<Pamphlet::fptr>( &Guest::Help ), 			"Help");
}

void Guest::Help(){
	printf("--Help You!\n");
}
void Guest::RequestPamphlet(){
	CustomerListType customers;
	CustomerType	 aCust;
	Login login;
	bool acctFail = true;

	printf("We require some information about you\n");
	//customers.AddFromFile("CustomerList.txt");	// handles looping
	customers.AddFromConsole();
	printf("after\n");
	customers.PrintList();

	/*
	printf("Create a pamphlet account\n");
	login.InitializeInfo("LoginInfoTest.txt");
	while(acctFail){
		try{
			login.NewAccount("LoginInfoTest2.txt");
			acctFail = false;
		}
		catch(Login::UsernameTaken()){
			printf("User Name Is Taken\n");
		}
	}
	printf("Account Created! Restart Pamphlet to Login\n");
	*/
}

