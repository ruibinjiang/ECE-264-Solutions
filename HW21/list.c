/*
Modify the file at the said location
*/
#include "list.h"
#include <stdlib.h>

#ifdef DO_NOT_MODIFY
ListNode * ListNode_create(TreeNode * tn)
{
  ListNode * ln = malloc(sizeof(ListNode));
  ln -> next = NULL;
  ln -> tnptr = tn;
  return ln;
}
// head may be NULL
// ln must not be NULL
// ln -> next must be NULL
ListNode * List_insert(ListNode * head, ListNode * ln)
{
  if (ln == NULL)
    {
      printf("ERROR! ln is NULL\n");
      return NULL;
    }
  if ((ln -> next) != NULL)
    {
      printf("ERROR! ln -> next is not NULL\n");
    }
  if (head == NULL)
    {
      return ln;
    }
    ln -> next = head;
    return ln;
}


#endif


/*
------------------------------------------------------------------------------
You Can Modify below, Do Not modify above this
------------------------------------------------------------------------------
*/


#ifdef TEST_MERGELIST

ListNode * MergeListNode(ListNode * head)
{
  /*
  This function is same as you did in HW20
  */
  ListNode * second = head -> next;
  // second must not be NULL, otherwise, will not enter
  ListNode * third  = second -> next;
  // third may be NULL
  // get the tree nodes of the first two list nodes
  TreeNode * tn1 = head -> tnptr;
  TreeNode * tn2 = second -> tnptr;
  // remove the first two nodes
  free (head);
  free (second);
  head = third;
  TreeNode * mrg;
  mrg = Tree_merge(tn2, tn1);
  ListNode * ln = ListNode_create(mrg);
  head = List_insert(head, ln);

  return head;
}
#endif
