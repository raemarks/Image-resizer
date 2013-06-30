#ifndef __IMAGE_H__
#define __IMAGE_H__

typedef struct image {
	char *filename;
	char header[3];
	int sizeX, sizeY, max;
	unsigned char *gypixels; //gray pixels for PGM
	unsigned char *rpixels; //red green and blue pixels for PPM
	unsigned char *gpixels;
	unsigned char *bpixels;
} Image;

/*shrinks an image to desired size specified by number of pixels in each direction*/
Image shrinkImagePixels (Image image, int sizeX, int sizeY);

/*shrinks an image to a new size with the desired ratio to the original image. Aspect
 * ratio is left intact*/
Image shrinkImageRatio (Image image, double ratio);

/*reads an image from a filename, returns the struct containing the image information*/
Image readImage (const char* filename);

/*same as corresponding shrink function, but enlarges*/
Image enlargeImagePixels (Image image);

/*same as corresponding shrink function, but enlarges*/
Image enlargeImageRatio (Image image, double ratio);

/*calculates desired number of pixels in y direction for a given number of pixels in the
 * x direction to maintain original aspect ratio of provided image*/
int calcSizeY (Image image, int sizeX);

/*calculates desired number of pixels in y direction for a given number of pixels in the
 * x direction to maintain original aspect ratio of provided image*/
int calcSizeX (Image image, int sizeY);

/*returns the number of pixels in the x direction of the provided Image struct*/
int getSizeX (Image image);

/*returns the number of pixels in the y direction of the provided Image struct*/
int getSizeY (Image image);

#endif
