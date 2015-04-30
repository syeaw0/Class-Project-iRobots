#ifndef PAMPHLET_H_
#define PAMPHLET_H_

//Pamphlet class manages print options and contains the customer list
class Pamphlet
{
private:
//	CustomerList customers; //list of current current customers
//	Robot        robot; //robot class used to print robot info

public:
	Pamphlet(); //constructor
	virtual ~Pamphlet(); //destructor
	virtual void Help(); //help menu
//	virtual void PrintMenu(); //prints the main menu
	void PrintRobotInfo();  //prints the appropriate robot info
	void PrintRobotOptions(); //prints the three different options for robots
	void PrintRobotMaintenance(); //prints the maintenance plan available
	void PrintRobotPolicy(); //prints the return and garantee policy for robots
	void PrintTestimonials(); //prints testimonials
	void PrintContacts(); //prints the contact info for our company
	bool SignOut(); //returns true if user can sign out
};


#endif /* PAMPHLET_H_ */

