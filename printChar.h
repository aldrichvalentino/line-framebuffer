#ifndef PRINTCHAR_H
#define PRINTCHAR_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

void line(int x0, int y0, int x1, int y1);

#endif