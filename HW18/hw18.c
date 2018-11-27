//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	// call print Function

	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2).
	Look at README, and expected output for more details.
	*/
	ListNode *search1 = head;
	ListNode *search2 = search1->next;
	ListNode *min1;
	ListNode *min2;

	int searchDist =  FindDist(search1->treenode, search2->treenode);
	int minDist = searchDist;

	while(search1 != NULL)
	{
		while(search2 != NULL)
		{
			searchDist = FindDist(search1->treenode, search2->treenode);

			if (searchDist <= minDist)
			{
				minDist = searchDist;
				min1 = search1;
				min2 = search2;
			}

			search2 = search2->next;
		}
		search1 = search1->next; //Continue to Analyze Next Element.

		if (search1 != NULL) //Compare to following element.
		{
			search2 = search1->next;
		}
	}

	int i = 0;
	while(i < min1->treenode->dimension)
	{
		if (min1->treenode->data[i] < min2->treenode->data[i])
		{
			PrintAnswer(head,min1,min2);
			i = min1->treenode->dimension;
		}
		else if (min2->treenode->data[i] < min1->treenode->data[i])
		{
			PrintAnswer(head,min2,min1);
			i = min1->treenode->dimension;
		}
		++i;
	}
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	int sum = 0;  // must initialize to zero
	int diff;

	for (int i = 0; i < x -> dimension; i++){
		diff = x -> data[i] - y -> data[i];
		sum = sum + diff * diff;
	}
	return sum;
	// return the distance
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
	ListNode*newNode = malloc(sizeof(ListNode));
	if(newNode==NULL){
		return NULL;
	}

	TreeNode*newTNode = malloc(sizeof(TreeNode));
	if(newTNode==NULL){
		return NULL;
	}
	// initialize dim
	newTNode->dimension=dim;
	// both left and right childern will be NULL
	newTNode->left=NULL;
	newTNode->right=NULL;
	// allocate memory for data
	newTNode->data=malloc(sizeof(int) * dim);
	for (int i = 0; i < dim; ++i)
  {
    newTNode->data[i] = arr[i];
  }
	// return a ListNode
	newNode->next = NULL;
	newNode->treenode=newTNode;
	return newNode;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	int*arr=malloc(sizeof(int)*dim);
	if (arr == NULL)
  {
    return;
  }

	for(int i = 0; i<dim;i++){
		fscanf(fptr, "%d", &arr[i]);
	}


	// read from file into an array, pass array to CreateNode
	ListNode*tempNode = CreateNode(0,dim,arr);
	// assign temp to that node
	*head = tempNode;
	// use a loop to create nodes for the remaining elements of the list.
	for (int count = 1; count < n; ++count)
  {
    for (int i = 0; i < dim; ++i)
    {
      fscanf(fptr, "%d", &arr[i]);
    }

    while((tempNode->next) != NULL)
    {
      tempNode = tempNode->next;
    }

    tempNode->next = CreateNode(n, dim, arr);
  }

  free(arr);

}
#endif
