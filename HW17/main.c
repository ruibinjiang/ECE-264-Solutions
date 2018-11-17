#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//***** YOU NEED TO MODIFY main() FUNCTION BELOW *******//
#ifdef TEST_MAIN

void _treeDestroy(treeNode *n);

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    return EXIT_FAILURE;
  }


  FILE *fptr = fopen(argv[1], "r");

  if (fptr == NULL)
  {
    return EXIT_FAILURE;
  }


  int value;
  int num = 0;
  while(fscanf(fptr, "%d", &value) == 1)
  {
    ++ num;
  }


  int *arr = malloc(sizeof(int) * (num - 1));
  int search_query;

  if (arr == NULL)
  {
    return EXIT_FAILURE;
  }

  fseek(fptr, 0, SEEK_SET);
  int index = 0;
  while(index < (num - 1))
  {
    if (fscanf(fptr, "%d", &arr[index]) != 1)
    {
      return EXIT_FAILURE;
    }
    ++index;
  }


  fscanf(fptr, "%d", &search_query);
  fclose(fptr);



  treeNode * root = CreateBST(arr, num-1, 0, (num - 2));


  BinaryTreeInOrderPrint(root);


  int dist = FindDistance(root, search_query, 0);

  PrintDistance(dist);

  free(arr);
  _treeDestroy(root);

}

void _treeDestroy(treeNode *n){
  if(n==NULL){return;}
  _treeDestroy(n->leftChild);
  _treeDestroy(n->rightChild);
  free(n);
}
#endif
