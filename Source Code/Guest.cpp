/**********************************************
 * AUTHOR		: David Stephan
 * PROJECT #2	: iRobots
 * CLASS		: CS1C
 * DUE DATE		: 5/15/15
 **********************************************/

#include "Guest.h"

Guest::Guest() {
	initMenu();
}
void Guest::initMenu(){
	insertOption(static_cast<Pamphlet::fptr>( &Guest::RequestPamphlet ),	"Request Pamphlet");
	insertOption(static_cast<Pamphlet::fptr>( &Guest::Help ), 				"Help");
}
void Guest::Help(){
	printf("--Help You!\n");
}
void Guest::RequestPamphlet(){
	printf("--Buy Robot\n");
}


