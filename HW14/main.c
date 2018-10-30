/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	if (argc < 2){
		return EXIT_FAILURE;
	}
	// input file is specified through the Makefile.

	// open file to read
	FILE*file = fopen(argv[1],"r");
	// check for fopen fail. If so, return EXIT_FAILURE
	if(file==NULL){
		return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int num_int = 0;
	int val = 0;
	while(fscanf(file, "%d", &val) == 1)
	{
		++num_int;
	}
	// allocate memory to store the numbers
	int * int_array = malloc(sizeof(int) * num_int);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (int_array == NULL)
	{
		fclose(file);
		return EXIT_FAILURE;
	}
	// use fscanf to read the file, and store its contents into an array.
	fseek (file, 0, SEEK_SET);
	int index = 0;

  while (index < num_int)
  {
    if (fscanf(file, "%d", & int_array[index]) != 1)
    {
      fclose (file);
      free (int_array);
      return EXIT_FAILURE;
    }
    index ++;
  }

  fclose(file);
	// create head node to store the head of the linked list.
	Node * head_node = NULL;
	head_node = malloc(sizeof(Node));

	if (head_node == NULL){
		return EXIT_FAILURE;
	}

	head_node->value = int_array[0];
	head_node->next = NULL;
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	LinkedListCreate(&head_node, num_int,int_array);
	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
	MergeSort(&head_node);
	// use the provided function to print the final list.
	LinkedListPrint(&head_node);
	// Tip: Check for memory errors.

	return EXIT_SUCCESS;
}

#endif
