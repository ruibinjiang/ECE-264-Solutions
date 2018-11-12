/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw16.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_FREETREE
// FreeBinaryTree
// This function frees up the memory from the root node

void FreeBinaryTree(treeNode *root)
{
    if (root == NULL){ return;}

    /* first delete both subtrees */
    deleteTree(root->left);
    deleteTree(root->right);

    /* then delete the node */
    free(root);
}

#endif

#ifdef TEST_SEARCH
// This function recursively searches for a given value in a tree
// and returns the node which has that value
treeNode* search(treeNode * tn, int value)
{
    treeNode* L = NULL;
    treeNode* R = NULL;
    if (tn == NULL) {
          return NULL;
    }

    if((tn->value)==value){
        return tn;
    }
    L = search(tn->left,value);
    if((L != NULL) && (L->value == value)){return tn;}
    R = search(tn->right,value);
    if((R != NULL) && (R->value == value)){return tn;}
    return NULL;
}

#endif


#ifdef TEST_SUBTREE
/* This function checks if `needle` is subtree of `haystack`. By subtree, it means that all the values of
*  `needle` are in `haystack`. For example in Example 1 (README),
*  treeNode with value 10 in Tree1 is subtree of Tree2 but Tree1 is not subtree of Tree2 . Please note this function is different from `isContained`,
* as it recursively compares two Trees/subtrees from the treeNodes given as input.
* It is consistent with  strstr function in C i.e. "strstr(const char \*haystack, const char \*needle)"
*/
bool isSubTree(treeNode* haystack, treeNode *needle)
{
  bool L = true;
  bool R = true;
  if (needle == NULL) {
        return true;
  }
  if((haystack->value)!= (needle->value)){
      return false;
  }

  L = isSubTree(haystack->leftChild,needle->leftChild);
  if(haystack->value != needle->value){return false;}
  R = isSubTree(haystack->rightChild,needle->rightChild);
  if(haystack->value != needle->value){return false;}
  return true;
}
#endif



#ifdef TEST_CONTAINED
// returns true if needle is contained in haystack
// returns false if needle is not contained in haystack
// needle and haystack may NOT be binary search tree
// Please note that order of arguments are important
// It is consistent with  strstr function in C i.e.
// "strstr(const char \*haystack, const char \*needle)"
bool isContained(treeNode * haystack, treeNode * needle)
{

}


#endif
