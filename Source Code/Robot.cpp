/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * ASSIGN # 13	: Recursion
 * CLASS		: CS1C
 * DUE DATE		: 4/21/15
 **********************************************/

#include "Robot.h"

// Default Constructor
Robot::Robot()
{

}

// Destructor
Robot::~Robot()
{

}

// Read in info from file
void Robot::Initialize(string inputFile)
{
	// VARIABLE DECLARATIONS
	ifstream inFile;

	// OPEN FILE
	inFile.open(inputFile.c_str());

	// GET ROBOT INFO FROM FILE
	getline(inFile, salesPitch);
	getline(inFile, environment);
	getline(inFile, operations);
	getline(inFile, options);
	getline(inFile, maintenance);
	getline(inFile, policy);

	// CLOSE FILE
	inFile.close();
}

// Return sales pitch
string Robot::GetSalesPitch()	const
{
	return salesPitch;
}

// Return environment
string Robot::GetEnvironment()	const
{
	return environment;
}

// Return operations
string Robot::GetOperations()	const
{
	return operations;
}

// Return options
string Robot::GetOptions()		const
{
	return options;
}

// Return maintenance
string Robot::GetMaintenance()	const
{
	return maintenance;
}

// Return policy
string Robot::GetPolicy()		const
{
	return policy;
}
