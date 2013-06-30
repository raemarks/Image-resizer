#include "image.h"

#include <stdio.h>

int main (void) {
	const char *filename = "red-wing-binary.ppm";
	Image *image;

	image = readImage(filename);
	//printf("after read function!\n");
	writeImage("red_wing2.ppm", image);

	return 0;
}
