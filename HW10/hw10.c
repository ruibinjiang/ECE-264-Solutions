#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
	if(argc != 2){return EXIT_FAILURE;}
  // open the BMP file
	BMPImage * image = BMP_Open(argv[1]);
  // convert to gray scale
	BMPImage * image = ImgToGray(image);
	// check for error in converting to gray scale

	// write the gray image to file
	// free all the images
	return EXIT_SUCCESS;
}

#endif
