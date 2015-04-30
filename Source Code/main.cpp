
#include "CustomerListType.h"
#include "CustomerType.h"

int main()
{

	CustomerListType customerList;
	char 			 ans;
	CustomerType	 aCust;

	customerList.AddFromFile("CustomerList.txt");

	customerList.PrintAllCustomerList();

	do
	{
		customerList.AddFromConsole();

		cout << "Add another? (y/n): ";
		cin.get(ans);
		ans = toupper(ans);
		cin.ignore(1000, '\n');

		customerList.PrintList();
	}while(ans != 'N');

	aCust.SetName("Jinko");

	customerList.Search(aCust);

	customerList.CustomerSearch("Jinko");

	customerList.PrintAllCustomerList();
	customerList.PrintKeyCustomerList();

	customerList.DeleteACustomer("Jinko");
	customerList.PrintAllCustomerList();

	customerList.SaveList("Test.txt");

	return 0;
}
