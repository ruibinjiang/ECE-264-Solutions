// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
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
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
	int *avg = malloc(sizeof(int) * x->dimension);

	for (int i = 0; i < x->dimension; ++i)
	{
		avg[i] = (x->data[i] + y->data[i]) / 2;
	}

	ListNode *new = CreateNode(0, x->dimension, avg);
  new->treenode->left = x;
  new->treenode->right = y;

	free(avg);
	return new;
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	int sum = 0;  // must initialize to zero
	int diff;

	for (int i = 0; i < x -> dimension; i++){
		diff = x -> data[i] - y -> data[i];
		sum = sum + diff * diff;
	}
	return sum;
}
#endif


#ifdef TEST_FUSE
ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{

	// Create a new ListNode element using findCentroid function.
	ListNode*new=FindCentroid(fuse1->treenode,fuse2->treenode);
	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
	new->next = head;
	head = new;
	ListNode*temp = head;
	// add the new ListNode to the list.
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
	while(head!=NULL && head->next != fuse1){
		head=head->next;
	}
	head->next = fuse1->next;
	head = temp;
	while(head!=NULL && head->next != fuse2){
		head=head->next;
	}
	head->next = fuse2->next;

	return temp;
	// you may want to return head from this function (depending on your implementation)
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
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

#ifdef TEST_CLUSTER
void MakeCluster(ListNode** head)
{
	// Walk through the linked list.
	// find pair of nodes with minimum distance.
	// fuse the two nodes into one node.
	// call print function
	// repeat till one node is remaining.
	ListNode *search1 = *head;
	ListNode *search2 = search1->next;
	ListNode *min1;
	ListNode *min2;

	int count = 1;
	while(search1->next!=NULL){
		count++;
		search1=search1->next;
	}
	search1=*head;

	int searchDist =  FindDist(search1->treenode, search2->treenode);
	int minDist = searchDist;

	while(count>1){
		search1 = *head;
		search2 = search1->next;

		searchDist =  FindDist(search1->treenode, search2->treenode);
		minDist = searchDist;

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
				PrintAns(*head,min1,min2);
				*head = Fuse(*head,min1,min2);
				i = min1->treenode->dimension;
				count--;
			}
			else if (min2->treenode->data[i] < min1->treenode->data[i])
			{
				PrintAns(*head,min2,min1);
				*head = Fuse(*head,min2,min1);
				i = min1->treenode->dimension;
				count--;
			}
			++i;
		}
	}
}
#endif
