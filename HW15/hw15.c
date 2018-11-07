/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
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

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
	// open file to read
	FILE*file = fopen(name,"r");

	if(file==NULL){
		return;
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
		return;
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
			return;
		}
		index ++;
	}

	Node *temp = *head;
	temp->value=int_array[0];
  for (int i = 1; i < num_int; ++i)
  {
    while((temp->next) != NULL) //Goes to End of Linked List (Should we reset head to )
    {
      temp = temp->next;
    }
    temp->next = CreateNode(int_array[i]); //Inserts new node at the end of list.
  }
	free(int_array);
	fclose(file);
	return;
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/
	Node * tempNode = headRef->next;
	Node * traverse = headRef;
	int live = 1;
	while(tempNode!=NULL){
		while(traverse->next!=tempNode){
			if(traverse->value == tempNode->value){live=0;}
			traverse=traverse->next;
		}
		if(live==0||traverse->value == tempNode->value){
			traverse->next = tempNode->next;
			free(tempNode);
			tempNode = traverse->next;
		}
		else{
			tempNode = tempNode->next;
		}
		live=1;
		traverse=headRef;
	}
}
#endif
