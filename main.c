#include "printChar.h"

int main() {
	int length, i, j;
	char * Name;
	char * Name2;

	length = 4;
    Name = (char*) malloc(length);
    Name[0] = 'a';
    Name[1] = 'm';
    Name[2] = 'u';
    Name[3] = 'z';

    Name2 = (char*) malloc(length);
	Name2[0] = 'i';
    Name2[1] = 'c';
    Name2[2] = 'h';
    Name2[3] = 'a';

    for (i = 30; i > 0; i--) {
    	printName(Name, length, i-0);
    	printName(Name2, length, i-160);	
    	
    	for(j = 0; j < 5000000; j++);
		clearScreen();
    }
    
  	
	
	return 0;
}
