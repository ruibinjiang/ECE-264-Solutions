/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
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
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");

}
#endif


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
	Node * new = malloc(sizeof(Node));
	// check memory allocation fails
	if(new == NULL){
		return NULL;
	}
	// create a Node* with the value as 'value'(input argument).
	new->next=NULL;
	new->value = value;
	return new;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// check if length is not negative
	if(length < 0){
		return;
	}
	Node * temp = *head;

	// create linked list of length as 'length'
	for(int i = 1; i < length; i++){
		while((temp->next)!=NULL){
			temp = temp->next;
		}
		temp ->next = CreateNode(i);
	}

	// do not return anything
	return;
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
	Node*lst=*head;
	Node*cur=lst->next;
	Node*nhead=*head;

	//get length
	int length = 1;
  while((lst->next) != NULL)
  {
    lst = lst->next;
    length++;
  }
	lst = *head;
	int num_alive = length;


	int kill_num = 2;
	while(num_alive > 1){
		if(kill_num==k&&cur==nhead){
			nhead=cur->next;
			free(cur);
			cur=nhead->next;
			kill_num = 1;
			num_alive--;
			if(!(num_alive % elemDivisible)){
				LinkedListPrint(nhead);
			}
			lst=lst->next;
			cur=cur->next;
		}
		else if(kill_num==k){
			lst->next=cur->next;
			free(cur);
			cur=lst->next;
			kill_num = 1;
			num_alive--;
			if(!(num_alive % elemDivisible)){
				LinkedListPrint(nhead);
			}
			lst=lst->next;
			cur=cur->next;
		}
		else{
			kill_num++;
			lst=lst->next;
			cur=cur->next;
		}
		if(cur==NULL){cur=nhead;}
		else if(lst==NULL){lst=nhead;}
	}
	//LinkedListPrint(*head);

	return;
}

#endif
