// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
int i;
for (i = 0; i < n - 1; i++){
	arr[i] = 1;
}  

  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked


int kill_num = 1;
int j = 0;
int num_alive = n;
while(num_alive > 1){
	if(arr[j]){
		if(kill_num == k){
			arr[j] = 0;
			printf(“%d\n”, j);
			kill_num = 1;
			num_alive—;
		}
		else{
			kill_num++;
		}
	}
	
	j++;
	if(j == n){
		j = 0;
	}
}
  // print the last one
int a;
for (a = 0; a < n - 1; a++){
	if(arr[a]){
		printf(“%d\n”,a);
	}
}  




  // release the memory of the array
  free (arr);
}
#endif
