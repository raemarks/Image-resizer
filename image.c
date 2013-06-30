#include "image.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Image *shrinkImagePixels (Image *image, int sizeX, int sixeY) {
	Image *newImage = (Image *) malloc (sizeof(Image));

	return newImage;
}

Image *shrinkImageRatio (Image *image, double ratio) {
	Image *newImage = (Image *) malloc (sizeof(Image));
	return newImage;
}

Image *readImage (const char* filename) {
	Image *newImage = (Image *) malloc (sizeof(Image));
	int i;
	int gy, r, g, b; //pixel values, used if file is in plain text
	newImage->filename = (char *) malloc (strlen(filename) + 1);
	strcpy(newImage->filename, filename);

	FILE *infile = fopen(newImage->filename, "r");
	fscanf(infile, "%s", newImage->header);
	fscanf(infile, "%d%d%d", &newImage->sizeX, &newImage->sizeY, &newImage->max);

	if (strcmp(newImage->header, "P2") == 0) { //.pgm plain text
		newImage->gypixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);

		for (i = 0; i < newImage->sizeX*newImage->sizeY; i++) {
			fscanf(infile, "%d", &gy);
			newImage->gypixels[i] = gy; //implicit typecast
		}	
	} else if (strcmp(newImage->header, "P3") == 0) { //.ppm plain text
		newImage->rpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);
		newImage->gpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);
		newImage->bpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);

		for (i = 0; i < newImage->sizeX*newImage->sizeY; i++) {
			fscanf(infile, "%d%d%d", &r, &g, &b);
			newImage->rpixels[i] = r; //implicit typecast
			newImage->gpixels[i] = g; //implicit typecast
			newImage->bpixels[i] = b; //implicit typecast
		}	
	} else if (strcmp(newImage->header, "P5") == 0) { //.pgm binary
		newImage->gypixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);

		for (i = 0; i < newImage->sizeX*newImage->sizeY; i++) {
			fscanf(infile, "%hhu", &newImage->gypixels[i]);
		}	
	} else if (strcmp(newImage->header, "P6") == 0) { //.ppm binary
		newImage->rpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);
		newImage->gpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);
		newImage->bpixels = (unsigned char *) malloc(sizeof(unsigned char) * newImage->sizeX*newImage->sizeY);

		for (i = 0; i < newImage->sizeX*newImage->sizeY; i++) {
			newImage->rpixels[i] = fgetc(infile);
			newImage->gpixels[i] = fgetc(infile);
			newImage->bpixels[i] = fgetc(infile);
		}	
	} 

	fclose(infile);
	return newImage;
}

void *writeImage (const char *filename, Image *image) {
	FILE *outfile = fopen(filename, "w");
	int i;

	fprintf(outfile, "%s\n%d %d %d\n", image->header, image->sizeX, image->sizeY, image->max);

	if (strcmp(image->header, "P2") == 0) { //plain text .pgm
		for (i = 0; i < (image->sizeX*image->sizeY); i++) {
			fprintf(outfile, "%d ", (int) image->gypixels[i]);
		}
	} else if (strcmp(image->header, "P3") == 0) { //plain text .ppm
		for (i = 0; i < (image->sizeX*image->sizeY); i++) {
			fprintf(outfile, "%d %d %d ", (int) image->rpixels[i], (int) image->gpixels[i], (int) image->bpixels[i]);
		}
	} else if (strcmp(image->header, "P5") == 0) { //binary .pgm
		for (i = 0; i < (image->sizeX*image->sizeY); i++) {
			fprintf(outfile, "%hhu", image->gypixels[i]);
		}
	} else if (strcmp(image->header, "P6") == 0) { //binary .ppm
		for (i = 0; i < (image->sizeX*image->sizeY); i++) {
			fputc(image->rpixels[i], outfile);
			fputc(image->gpixels[i], outfile);
			fputc(image->bpixels[i], outfile);
		}
	}
}

Image *enlargeImagePixels (Image *image) {
	Image *newImage = (Image *) malloc (sizeof(Image));

	return newImage;
}

Image *enlargeImageRatio (Image *image, double ratio) {
	Image *newImage = (Image *) malloc (sizeof(Image));

	return newImage;
}

int calcSizeY (Image *image, int sizeX) {
	int y;

	return y;
}

int calcSizeX (Image *image, int sizeY) {
	int x;

	return x;
}

int getSizeX (Image *image) {
	return image->sizeX;
}

int getSizeY (Image *image) {
	return image->sizeY;
}
