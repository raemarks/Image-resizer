#include "image.h"

#include <stdio.h>

int main (void) {
	const char *filename = "COUGAR2.ppm";
	Image *image;

	image = readImage(filename);
	//printf("after read function!\n");
	writeImage("coug2.ppm", image);
	
	return 0;
}
