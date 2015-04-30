/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * ASSIGN # 13	: Recursion
 * CLASS		: CS1C
 * DUE DATE		: 4/21/15
 **********************************************/

#ifndef ROBOT_H_
#define ROBOT_H_

// PRE-PROCESSOR DIRECTIVES

#include <fstream>
#include <string>
using namespace std;

/****************************************************************
 * CLASS Robot
 * --------------------------------------------------------------
 * This class contains all information pertaining to the iRobot,
 * such as options for the robot, maintenance plans, and
 * environment capabilities.
 ****************************************************************/
class Robot
{
private:
	/*ATTRIBUTES*/
	string salesPitch;		// The sales pitch
	string environment;		// The environments the robot is compatible with
	string operations;		// The operations of the robot
	string options;			// The different options available
	string maintenance;		// The maintenance plan
	string policy;			// The policy for the robot

public:
	/*METHODS*/
	Robot();	// Default Constructor
	~Robot();	// Destructor

	// MUTATORS
	void Initialize(string inputFile);	// Initializes the robots info from
										// a file

	// ACCESSORS
	string GetSalesPitch()	const;		// Returns the sales pitch
	string GetEnvironment() const;		// Returns the environments
	string GetOperations()  const;		// Returns the operations
	string GetOptions()		const;		// Returns the robot options
	string GetMaintenance()	const;		// Returns the maintenance plans
	string GetPolicy()		const;		// Returns the company policy
};

#endif /* ROBOT_H_ */
