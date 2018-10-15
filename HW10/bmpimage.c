#include "bmpimage.h"
// Modify all functions in this file



#ifdef TEST_HEADERVALID

/* check whether a header is valid or not
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this assignment
 * in general, the format is more complicated and requires more checks
 */

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
		// Make sure this is a BMP file -  magic number
		// skip the two unused reserved fields

		// check the offset from beginning of file to image data
		// essentially the size of the BMP header
		// BMP_HEADER_SIZE for this exercise/assignment
		// printf("header->offset %d\n",header->offset );

	  // check the DIB header size == DIB_HEADER_SIZE
		// Make sure there is only one image plane
		// Make sure there is no compression

		// skip the test for xresolution, yresolution

		// ncolours and importantcolours should be 0
		// Make sure we are getting 24 bits per pixel
		// only for this assignment
		// extra check for file size, image size
		// based on bits, width, and height

		// check out the link: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage
		if (( header -> type ) != 0X4D42 )
		{
			return 0;
		}
		if (( header -> offset ) != BMP_HEADER_SIZE )
		{
			return 0;
		}
		if (( header -> DIB_header_size ) != DIB_HEADER_SIZE )
		{
			return 0;
		}
		if (( header -> bits ) != 24 )
		{
			return 0;
		}
		if (( hheaderdr -> planes ) != 1 )
		{
			return 0;
		}
		if (( header -> compression ) != 0 )
		{
			return 0;
		}
		if (( header -> ncolours ) != 0 )
		{
			return 0;
		}
		if (( header -> importantcolours ) != 0 )
		{
			return 0;
		}
		if (( header -> imagesize ) != ((header->bits)*(header->xresolution)*(header->yresolution)))
		{
			return 0;
		}
		if (( header -> size ) != ((header->bits)*(header->xresolution)*(header->yresolution) + 54))
		{
			return 0;
		}

		return TRUE;
}

#endif



#ifdef TEST_BMPOPENFILE
/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */


BMPImage *BMP_Open(const char *filename) {
  //open file
  //read file
	FILE *fptr = fopen(filename,"r");

	//Allocate memory for BMPImage*;

	BMPImage *bmpImage = (BMPImage *)malloc(sizeof(BMPImage));
	//check for memory allocation errors
	if (bmpImage == NULL){return NULL;}

	//Read the first 54 bytes of the source into the header
	int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);

	//check if the header is valid
	if (Is_BMPHeader_Valid(bmpImage -> header, fptr) == 0){return NULL;}
	// Allocate memory for image data
	//(bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize))))
	//check error
	bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize)));
	// read in the image data
	int read_data = fread(bmpImage -> data,sizeof (char) , (int)((bmpImage->header).imagesize)) ,fptr);
	//check for error while reading
	if(read_data != (int)((bmpImage->header).imagesize))){return NULL;}
	fclose(fptr);
	return bmpImage;
}
#endif


#ifdef TEST_BMPWRITEFUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* image)
{
	FILE *fptr = fopen(outfile, "w");
	//open file and check for error
	if(fptr == NULL){return 0;}
	//check error for writing
	if (fwrite (& (image -> header ) , sizeof(BMP_Header) , 1,fptr) != 1){
		fclose(fptr);
		return 0;
	}
	// write and check for image data:(fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize)
	if (fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize){
		fclose(fptr);
		return 0;
	}
	fclose(fptr);
	return TRUE;
}

#endif
/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifdef TEST_BMPFREEFUNC
void BMP_Free(BMPImage* image) {
	//free image if image is true
	free(image -> data);
	free(image);
}

#endif
