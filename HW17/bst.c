#include "bst.h"
///***** DO NOT MODIFY THIS FUNCTION ******/////
#ifdef TEST_PRINT
void PrintDistance(int distance)
{

    printf("\n%d\n",distance);

}
///***** DO NOT MODIFY THIS FUNCTION ******/////
void BinaryTreePrint(treeNode* tn)
{
        printf("Pre Order print of the Tree is: \n");
        BinaryTreePreOrderPrint(tn);
        printf("\nIn Order print of the Tree is: \n");
        BinaryTreeInOrderPrint(tn);
        printf("\nPost Order print of the Tree is: \n");
        BinaryTreePostOrderPrint(tn);
        printf("\n");
}
///***** DO NOT MODIFY THIS FUNCTION ******/////
// print the tree in pre order fashion
void BinaryTreePreOrderPrint(treeNode* tn)
{
        if(tn == NULL)
                return;
        printf("%d ",tn->value );
        BinaryTreePreOrderPrint(tn->leftChild);
        BinaryTreePreOrderPrint(tn->rightChild);
}
///***** DO NOT MODIFY THIS FUNCTION ******/////
// print the tree in in order fashion
void BinaryTreeInOrderPrint(treeNode* tn)
{
        if(tn == NULL)
                return;
        BinaryTreeInOrderPrint(tn->leftChild);
        printf("%d ",tn->value );
        BinaryTreeInOrderPrint(tn->rightChild);
}
///***** DO NOT MODIFY THIS FUNCTION ******/////
// print the tree in post order fashion
void BinaryTreePostOrderPrint(treeNode *tn)
{
        if(tn == NULL)
                return;
        BinaryTreePostOrderPrint(tn->leftChild);
        BinaryTreePostOrderPrint(tn->rightChild);
        printf("%d ",tn->value );
}

///******* DO NOT MODIFY ABOVE THIS LINE. YOU MAY MODIFY BELOW *******////

///***** MODIFY THIS FUNCTION ******/////
//this function calculates the distance of a node from the root, given the tree, the value to search.
#endif
#ifdef TEST_DIST
int FindDistance(treeNode* t, int search_query, int distance)
{

	/*
	 * This function recursively checks for the value of search_query in the tree.
	 * Use the properties of binary search tree in order to search for the search_query.
	 * if a match is found, return distance.
	 * if not, recursively call, either the left child or the right child, search_query and distance+1 as arguments.
	 * if the value 'search_query' does not exist in the tree, return -1.
	 *
	 */

        if(t==NULL){return -1;}

        if(search_query == (t->value))
        {
                return distance;
        }
        else if (search_query < (t->value))
        {
                distance = FindDistance(t->leftChild, search_query, (distance + 1));
        }
        else
        {
                distance = FindDistance(t->rightChild, search_query, (distance + 1));
        }

        return distance;
}
#endif
///***** MODIFY THIS FUNCTION ******/////
// this function creates a bst based on the given array
#ifdef TEST_CREATEBST
treeNode* CreateBST(int* a,int root, int start, int end)
{

	/*
	 *
	 * Create a node, allocate memort and assign the value of root to it.
	 * Based on the values, divide the array into two subarrays: left child and right.
	 *	Dividing here means to reassign the values of start and end for each sub array.
	 * Store the first value of every subarray as the root.
	 * Recursively call the CreateBST function with array, modified values of root, start and end.
	 * End Condition for recusion: check for relative positions of start and end. end can never be less than start.
	 * if start and end point to the same element in the array, then it is a leaf node. Assign the values of
	 *   its children accordingly.
	 *
	 *//////

        if(end < start || start > root){return NULL;}

        treeNode * newNode = malloc(sizeof(treeNode));
        root=a[start];
        newNode->value=root;
        if(end == start){
                newNode->leftChild = NULL;
                newNode->rightChild=NULL;
                return newNode;
        }
        int endL = start+1;
        while(a[endL]<root){
                ++endL;
        }
        --endL;

        newNode->leftChild = CreateBST(a, root, start+1, endL);

	newNode->rightChild = CreateBST(a, root, endL+1, end);

        return newNode;
}
#endif
