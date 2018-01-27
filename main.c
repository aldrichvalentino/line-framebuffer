#include "printChar.h"

int main() {
	int i, j;
	for(i = 30; i > 0; i--){
		printChar('a',0, i);
		printChar('l', 102, i);
		printChar('d', 204, i);
		printChar('r', 306, i);
		printChar('i', 408, i);
		printChar('c', 510, i);
		printChar('h', 612, i);

		for(j = 0; j < 5000000; j++);
		clearScreen();
	}
	
	return 0;
}
