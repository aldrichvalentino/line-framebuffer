#include "printChar.h"

void line(int x0, int y0, int x1, int y1) {
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0, timer = 0;
    long int location = 0;
    const int buffer = 79; // 80 x 80
    char A[buffer][buffer]; 
    int maxY;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    //printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    //printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (*fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }



  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    //setPixel(x0,y0);
	location = (x0+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y0+vinfo.yoffset) * finfo.line_length;

	*(fbp + location) = 255;        // Some blue
        *(fbp + location + 1) = 255;     // A little green
        *(fbp + location + 2) = 255;    // A lot of red
        *(fbp + location + 3) = 0;      // No transparency
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void printChar(char character){
    FILE *test;
    char i;
    int lines, j;
    test = fopen("characters/a.txt", "r");
    if(test != NULL){
        i = fgetc(test);
        lines = atoi(&i); // number of lines
        i = fgetc(test); // delete enter
        //printf("%d\n", lines*4);
        for(i = 0; i < lines; i++){
            int temp = 0, temp1 = 0, temp2 = 0, temp3 = 0;
            for(j = 0; j < 3; j++){
                char c = fgetc(test) - 48;
                //printf("ini temp %d dan ini char %c\n", temp, c);
                temp = temp*10 + c;
            }
            //printf("%d\n",temp);
            fgetc(test);

            for(j = 0; j < 3; j++){
                char c = fgetc(test) - 48;
                //printf("ini temp %d dan ini char %c\n", temp, c);
                temp1 = temp1*10 + c;
            }
            //printf("%d\n",temp1);
            fgetc(test);

            for(j = 0; j < 3; j++){
                char c = fgetc(test) - 48;
                //printf("ini temp %d dan ini char %c\n", temp, c);
                temp2 = temp2*10 + c;
            }
            //printf("%d\n",temp2);
            fgetc(test);

            for(j = 0; j < 3; j++){
                char c = fgetc(test) - 48;
                //printf("ini temp %d dan ini char %c\n", temp, c);
                temp3 = temp3*10 + c;
            }
            //printf("%d\n",temp3);
            fgetc(test);

            line(temp, temp1, temp2, temp3);
        }
    }
}