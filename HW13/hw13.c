/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw13.h"

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


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
	// Initialize "next", and "value" appropriately
	Node *new_node = NULL;
  new_node = malloc(sizeof(Node));
	if (new_node == NULL)
  {
    return NULL;
  }
  new_node->value = val;
  new_node->next = NULL;
	//return the newNode
	return new_node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// Tip: use CreateNode(arr[index])
	if (len <= 0)
  {
    return;
  }
	Node *temp = *source;

  for (int i = 1; i < len; ++i)
  {
    while((temp->next) != NULL) //Goes to End of Linked List (Should we reset head to )
    {
      temp = temp->next;
    }
    temp->next = CreateNode(arr[i]); //Inserts new node at the end of list.
  }

  return;
}
#endif


#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2)
{
	// Find the mid point of the list.
	int length = 0;
  Node *temp = source;
  while((temp->next) != NULL)
  {
    temp = temp->next;
    ++length;
  }

  int mid = 0;

  if (!(length % 2))
  {
    mid = floor(length/2);
  }
  else
  {
    mid = length/2;
  }
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4

		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5

    	// Tip: head1 will point to the source node.
	temp = source;
  *head1 = source;

  for (int i = 0; i < (mid); ++i)
  {
    temp = temp->next;
  }

  *head2 = temp->next;
  temp->next = NULL;
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
	return;
}
#endif


#ifdef TEST_DIV
void Divide(Node** source)
{
	int length = 0;
	Node *temp = *source;
	while((temp->next) != NULL)
	{
		temp = temp->next;
		++length;
	}

	if (length < 1)
	{
		return;
	}
	// Declare a node, to hold the current head of source list.
	Node *current_head = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
	Node *head1 = NULL;
  head1 = malloc(sizeof(Node));
  if (head1 == NULL)  //Check Memory allocation failure
  {
    return;
  }

  Node *head2 = NULL;
  head2 = malloc(sizeof(Node));
  if (head2 == NULL)  //Check Memory allocation failure
  {
    return;
  }

	// Check for the base case -- length 0 or 1
		// if so, return;

	// Use SpiltList(...) to partition the list into sub lists.
	SplitList(current_head, &head1, &head2);
	// Use LinkedListPrint(...); to print the upper sub-list.
	LinkedListPrint(&head1);
	// Use LinkedListPrint(...); to print the lower sub-list
	LinkedListPrint(&head2);
		// DO NOT USE YOUR OWN PRINT FUNCTION.

	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 Divide(&head1);
	 Divide(&head2);
	 // till only one or no elements are left in the sub-lists.
	 return;
}
#endif
