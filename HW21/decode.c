// Modify this file at said locations
#include "decode.h"
#include "list.h"
#include "utility.h"


/*
------------------------------------------------------------------------------
You Can Modify below, Do Not modify above this
------------------------------------------------------------------------------
*/

#ifdef TEST_READHEADER

TreeNode * readHeader(FILE * infptr)
{
  // This is the same function from HW20
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte  = 0;
  unsigned char onebit   = 0;
  ListNode * head = NULL;
  // decreasing to ensure the list is a stack
  while (done == 0)
    {
      readBit(infptr, & onebit, & whichbit, & curbyte);
      if (onebit == 1)
  {
    // a leaf node, get 7 move bits
    int bitcount;
    unsigned char value = 0;
    for (bitcount = 0; bitcount < 8; bitcount ++)
      {
        value <<= 1; // shift left by one
        readBit(infptr, & onebit, & whichbit, & curbyte);
        value |= onebit;
      }
    // push a tree node into the list
    TreeNode * tn = TreeNode_create(value, 0);
    ListNode * ln = ListNode_create(tn);
    head = List_insert(head, ln);
  }
      else
  {
    if (head == NULL)
      {
        //printf("ERROR, head should not be NULL\n");
      }
    if ((head -> next) == NULL)
      {
        // the tree has been completely built
        done = 1;
      }
    else
      {
        head = MergeListNode(head);
      }
     }
    }
  // unnecessary to read the remaining unused bits
  TreeNode * root = head -> tnptr;
  // the linked list is no longer needed
  free (head);
  return root;
}

#endif


#ifdef TEST_DECODE

int decode(char * infile, char * outfile)
{
  // In this function, in addition to the last assignment, you will also decode the rest of the file.
  // After getting the Huffman tree and number of character from the header file as in last assignment,
  // we will decode the rest the file as explained in README and will print each character in the `outfile`.
  // Thus, this function have 3 prints into the outfile - printing Huffman tree using Tree_print function
  // (same as in last assignment), then printing number of characters using PrintNumberChar
  // function (same as in previous assignment using) and then printing each decoded character into
  // the outfile.

  FILE * infptr = fopen(infile, "r");
  FILE *outfptr = fopen(outfile, "w");
  if (infptr == NULL)
    {
      return 0;
    }
  TreeNode * root = readHeader(infptr);
  Tree_print(root, outfptr);
  // read the number of characters
  unsigned int numChar = 0;
  fread(& numChar, sizeof(unsigned int), 1, infptr);

  // read '\n'
  unsigned char newline;
  fread(& newline, sizeof(unsigned char), 1, infptr);

  PrintNumberChar(numChar, outfptr);


  Tree_destroy(root);
  fclose(infptr);
  fclose(outfptr);
  return 1;
}
#endif
