/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw14.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
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
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

void LinkedListCreate(Node * * source, int len, int* arr)
{
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
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

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

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower)
{
	// Check for the base cases. (When either sub-list is NULL)
  if(upper == NULL){
    return(lower);
  }
  else if(lower == NULL){
    return(upper);
  }
  Node* sorted = NULL;
	// Pick the larger between upper and lower, and recur appropriately.
  if((upper->value)<=(lower->value))
  {
    sorted = upper;
    sorted->next = Merge(upper->next, lower);
  }
  else
  {
    sorted = lower;
    sorted->next = Merge(upper, lower->next);
  }
	// return the merged array
  return(sorted);
}
#endif

#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source)
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

	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
  SplitList(current_head, &head1, &head2);
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
  MergeSort(&head1);
  MergeSort(&head2);
	// Merge the two sorted lists together, using the Merge()
  *source = Merge(head1,head2);
}
#endif
