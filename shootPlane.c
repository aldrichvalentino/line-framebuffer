#include "printChar.h"

void shootPlane(int dx, int dy, int orientation) {
    if(orientation == -1){ // print to the left
        line(600, 700, 700, 800, dx, dy);
    } else if(orientation == 1) { //print to the right
        line(700, 800, 800, 700, dx, dy);
    } else if(orientation == 0) { // print straight
        line(700, 800, 700, 700, dx, dy);
    }
}