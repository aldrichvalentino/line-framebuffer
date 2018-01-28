#include "printName.h"

void printName(char* Name, int Length, int Y, int r, int g, int b) {
    int j;

	for (j = 0; j< Length; j++) {
		printChar(Name[j], j*120, Y, r, g, b);
	}

}
