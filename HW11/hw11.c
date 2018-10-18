#include "hw11.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments - please read readme about validity of arguments
	if(argc != 5){
		printf("Wrong arguments\n");
		return EXIT_FAILURE;
	}
  // check radius and epsilon values -  read readme for the validity of argument
	if(strtol(argv[3],NULL,10) < 0 || strtol(argv[4],NULL,10) < 0){
		printf("Wrong inputs\n");
		return EXIT_FAILURE;
	}
  // open the BMP file
	BMPImage * image = BMP_Open(argv[1]);
	if(image == NULL){
		printf("Error opening BMP file\n");
		return EXIT_FAILURE;
	}
  // convert to gray scale
	BMPImage * gray_image = ImgToGray(image);
	// check for error in converting to gray scale
	if(gray_image == NULL){
		printf("Error converting to Gray image\n");
		return EXIT_FAILURE;
	}
  // call adaptive threshold function
	BMPImage * adapt_image = AdaptiveThresholding(gray_image, strtol(argv[3],NULL,10), strtol(argv[4],NULL,10));
  // check for errors after calling adaptive threshold
	if(adapt_image == NULL){
		printf("Error in Adaptive Gray image\n");
		return EXIT_FAILURE;
	}
	// write the adaptive threshold image to file
	BMP_Write(argv[2], adapt_image);
	// free all the images
	BMP_Free(image);
	BMP_Free(gray_image);
	BMP_Free(adapt_image);
	return EXIT_SUCCESS;
}

#endif
