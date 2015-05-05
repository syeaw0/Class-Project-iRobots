
#ifdef MAIN_SPRINT2

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "CustomerListType.h"
#include "Pamphlet.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"


int main(){

	printf("test bbbb\n");
	FILE* f = fopen("text files/file2.txt", "r");

	if( f==NULL ){
		printf(" failed to open file\n" );
	}
	char inchar;
	while( fscanf(f, "%c", &inchar) != -1 ){
		printf("%c", inchar);
	}

	system("pause");

	Pamphlet* pamphlet = new Admin();
	pamphlet->menuLoop();
	delete pamphlet;

	pamphlet = new Guest();
	pamphlet->menuLoop();
	delete pamphlet;

	pamphlet = new Customer();
	pamphlet->menuLoop();
	delete pamphlet;
}

#endif
