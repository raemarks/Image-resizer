#include "image.h"

#include <stdio.h>

int main (void) {
	const char *filename = "red-wing-binary.ppm";
	Image image;

	image = readImage(filename);

	return 0;
}
