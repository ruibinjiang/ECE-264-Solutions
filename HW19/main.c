// Please modify this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"


#ifdef TEST_MAIN
void _killTree(TreeNode *tn);
void _killList (ListNode *head);

void _killList (ListNode *head)
{
  //Code Modified from HW15
  ListNode *temp;
  //Code Taken from ListDestroy() in Intermediate C Programming Textbook.
  while(head != NULL)
  {
    temp = head->next;
    _killTree(head->treenode);
    free(head);
    head = temp;
  }

  return;
}

void _killTree(TreeNode *tn)
{
  //Terminating Condition
  if (tn == NULL)
  {
    return;
  }
  _killTree(tn->left);
  _killTree(tn->right);
  free(tn->data);
  free(tn);

  return;
}
int main(int argc, char * * argv)
{
	// check for input error
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }
	// open the file
  FILE *fptr = fopen(argv[1], "r");
	// input file is in argv[1]
  if (fptr == NULL)
  {
    return EXIT_FAILURE;
  }
	// n is the element in the file
  int n;
  fscanf(fptr, "%d", &n);
	// dim is the second element in the file
  int dim;
  fscanf(fptr, "%d", &dim);
	// the rest of the data in the file are the datapoints.
  ListNode* head = NULL;

	// call LinkedListCreate
  LinkedListCreate(&head,n,dim,fptr);

	MakeCluster(&head);
	_killList (head);
	fclose(fptr);
	// call MakeCluster
}
#endif
