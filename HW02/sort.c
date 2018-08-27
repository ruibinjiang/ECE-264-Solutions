// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level

  // call checkOrder to see whether this function correctly sorts the
  // elements
  int sorted_index;
  int unsorted_index;
  int temp;
  int min_index;

  for(sorted_index = 0; sorted_index < size-1; sorted_index++){
    //find index of the minimum number in the array
    min_index = sorted_index;
    for(unsorted_index = sorted_index; unsorted_index < size; unsorted_index++){
        if(arr[unsorted_index] < arr[min_index])
          min_index = unsorted_index;
    }

    //switch the minimum number found with the first unsorted number
    temp = arr[min_index];
    arr[min_index] = arr[sorted_index];
    arr[sorted_index] = temp;
  }

  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
