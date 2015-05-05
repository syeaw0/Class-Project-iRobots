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
	printf("--Buy Robot\n");
}

