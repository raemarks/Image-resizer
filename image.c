#include "image.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Image shrinkImagePixels (Image image, int sizeX, int sixeY) {
	Image newImage;

	return newImage;
}

Image shrinkImageRatio (Image image, double ratio) {
	Image newImage;

	return newImage;
}

Image readImage (const char* filename) {
	Image newImage;
	int i;
	int gy, r, g, b; //pixel values, used if file is in plain text
	newImage.filename = (char *) malloc (strlen(filename) + 1);
	strcpy(newImage.filename, filename);

	FILE *infile = fopen(newImage.filename, "r");
	fscanf(infile, "%s", newImage.header);
	printf("Header: %s", newImage.header);
	fscanf(infile, "%d%d%d", &newImage.sizeX, &newImage.sizeY, &newImage.max);

	if (strcmp(newImage.header, "P2") == 0) { //.pgm plain text
		newImage.gypixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);

		for (i = 0; i < newImage.sizeX*newImage.sizeY; i++) {
			fscanf(infile, "%d", &gy);
			newImage.gypixels[i] = gy; //implicit typecast
		}	
	} else if (strcmp(newImage.header, "P3") == 0) { //.ppm plain text
		newImage.rpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);
		newImage.gpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);
		newImage.bpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);

		for (i = 0; i < newImage.sizeX*newImage.sizeY; i++) {
			fscanf(infile, "%d%d%d", &r, &g, &b);
			newImage.rpixels[i] = r; //implicit typecast
			newImage.gpixels[i] = g; //implicit typecast
			newImage.bpixels[i] = b; //implicit typecast
		}	
	} else if (strcmp(newImage.header, "P5") == 0) { //.pgm binary
		newImage.gypixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);

		for (i = 0; i < newImage.sizeX*newImage.sizeY; i++) {
			fscanf(infile, "%hhu", &newImage.gypixels[i]);
		}	
	} else if (strcmp(newImage.header, "P3") == 0) { //.ppm binary
		newImage.rpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);
		newImage.gpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);
		newImage.bpixels = (unsigned char *) malloc(newImage.sizeX*newImage.sizeY);

		for (i = 0; i < newImage.sizeX*newImage.sizeY; i++) {
			fscanf(infile, "%hhu", &newImage.rpixels[i]);
			fscanf(infile, "%hhu", &newImage.gpixels[i]);
			fscanf(infile, "%hhu", &newImage.bpixels[i]);
		}	
	} 

	return newImage;
}

Image enlargeImagePixels (Image image) {
	Image newImage;

	return newImage;
}

Image enlargeImageRatio (Image image, double ratio) {
	Image newImage;

	return newImage;
}

int calcSizeY (Image image, int sizeX) {
	int y;

	return y;
}

int calcSizeX (Image image, int sizeY) {
	int x;

	return x;
}

int getSizeX (Image image) {
	int x;

	return x;
}

int getSizeY (Image image) {
	int y;

	return y;
}
