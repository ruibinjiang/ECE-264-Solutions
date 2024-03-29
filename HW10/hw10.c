#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
	if(argc != 3){return EXIT_FAILURE;}
  // open the BMP file
	BMPImage * image = BMP_Open(argv[1]);
  // convert to gray scale
	BMPImage * gray_image = ImgToGray(image);
	// check for error in converting to gray scale
	if(gray_image == NULL){return EXIT_FAILURE;}
	// write the gray image to file
	BMP_Write(argv[2], gray_image);
	// free all the images
	BMP_Free(image);
	BMP_Free(gray_image);
	return EXIT_SUCCESS;
}

#endif
