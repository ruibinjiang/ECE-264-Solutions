/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw15.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// input argv[1] contains the name of the input file.
	// Check for the right number of input arguments.
  if (argc < 2){
		return EXIT_FAILURE;
	}
  char* name = argv[1];
	//Initialize a linked list Node and use the file name from input arguments to create a linked list
  Node * head_node = NULL;
	head_node = malloc(sizeof(Node));

	if (head_node == NULL){
		return EXIT_FAILURE;
	}

	head_node->value = 0;
	head_node->next = NULL;

  LinkedListCreate(&head_node, name);
	//Remove all duplicates in the linked list created above.
  RemoveDuplicate(head_node);
  LinkedListPrint(head_node);
	// release memory
  Node *temp = head_node;

  while(temp!=NULL)
  {
    temp=head_node->next;
    free(head_node);
    head_node = temp;
  }
}

#endif
