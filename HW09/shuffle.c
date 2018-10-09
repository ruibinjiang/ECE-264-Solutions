// Please modify this file as required

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _rec_me(CardDeck, char *, int , char *, int, int, int, int, int);
// You can add more functions, structures, and vairables to this file.
	// Helper functions must start with '_'.

//This is an example of a helper function.
	//clean function whenever malloc fails in shuffle function
/*static void _error_clean()
{
	exit(EXIT_FAILURE);

}*/

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck* upper_deck, CardDeck* lower_deck)
{
	//Dividing the desks into the way mentioned in the document - as lower and upper
	//Use a loop from index i to orig_deck.size - 1
		//starting from 1 -> size-1 copying into upper deck and lower decks
			//strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		//update size of upper deck
			//For example: upper_deck[i].size = i+1;
		//update size of lower deck:
			//For example: lower_deck[i].size = orig_deck.size -i -1;
			for(int i = 0; i<orig_deck.size - 1; i++){
					strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
					upper_deck[i].size = i+1;
					strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
					lower_deck[i].size = orig_deck.size -i - 1;
				}
}
#endif


#ifdef TEST_INTER
//repeat holds the number of shuffles yet to be performed.
//after the interleave operation has been completed, you will recursively call
	//repeat_shuffle(...) with a decremented value of repeat.
void interleave(CardDeck upper_deck, CardDeck lower_deck, int repeat)
{
    // Follow instructions in the README, to understand the working of the recursive function.

    // when the newly shuffled deck is complete:
    	//you will perform another k-1 rounds of shuffling with the new deck

    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
		CardDeck deck_fnl;
	 	deck_fnl.size = upper_deck.size + lower_deck.size;

		for (int i = 0; i < deck_fnl.size; i++){
			deck_fnl.cards[i] = 0;
		}

		int fnl_i = 0;
		int up_i = 0;
		int low_i = 0;

		char* upper = NULL;
		char* lower = NULL;

		upper = malloc(up_i * sizeof(upper_deck.cards[0]));
		lower = malloc(low_i * sizeof(lower_deck.cards[0]));
		for (int i = 0; i < upper_deck.size; ++i)
		{
			upper[i] = upper_deck.cards[i];
		}

		for (int i = 0; i < lower_deck.size; ++i)
		{
			lower[i] =  lower_deck.cards[i];
		}

		_rec_me(deck_fnl, upper, up_i, lower, low_i, fnl_i, upper_deck.size, lower_deck.size, repeat);
		free(upper);
		free(lower);
		return;

}

void _rec_me(CardDeck deck_fnl, char * upper, int up_i, char *lower, int low_i, int fnl_i, int upper_size, int lower_size, int repeat){
	if (up_i >= upper_size){
		for(int i = low_i; i < lower_size; ++i){
			deck_fnl.cards[fnl_i] = lower[i];
			++fnl_i;
		}
		repeat_shuffle(deck_fnl, repeat-1);
		return;
	}
	if (low_i >= lower_size){
		for(int i = up_i; i < upper_size; ++i){
			deck_fnl.cards[fnl_i] = upper[i];
			++fnl_i;
		}
		repeat_shuffle(deck_fnl, repeat-1);
		return;
	}

	deck_fnl.cards[fnl_i] = upper[up_i];
	_rec_me(deck_fnl, upper, up_i+1, lower, low_i, fnl_i+1, upper_size, lower_size, repeat);

	deck_fnl.cards[fnl_i] = lower[low_i];
	_rec_me(deck_fnl, upper, up_i, lower, low_i+1, fnl_i+1, upper_size, lower_size, repeat);
}
#endif

#ifdef TEST_SHUF
//repeat holds the number of shuffles that are yet to be performed.
void shuffle(CardDeck orig_deck, int repeat)
{
	// declare a variable to hold the number of pairs
			// we can say that we have only size-1 possibility of pairs
	int numpairs = orig_deck.size - 1;
	// if number of pairs == 0; return;
	if(numpairs == 0){return;}
// instantiate pointers to hold both upper and lower decks (after division)
	 // For example: CardDeck * upper_deck = NULL;
 CardDeck * upper_deck = NULL;
 CardDeck * lower_deck = NULL;
// allocate memory based on number of pairs
	 //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
 upper_deck = malloc(numpairs*sizeof(CardDeck));
 lower_deck = malloc(numpairs*sizeof(CardDeck));
// call divideDeck to fill upper_deck and lower_deck
divide(orig_deck, upper_deck, lower_deck);

//run a loop through all the pairs
	// for each pair of upper and lower deck call interleave()
	// For example: interleave(upper_deck[i],lower_deck[i]);
	for(int i = 0; i < numpairs; ++i){
		interleave(upper_deck[i],lower_deck[i], repeat);
	}
	// free memory allocated to upper and lower deck.
	free(upper_deck);
	free(lower_deck);
}
#endif

#ifdef TEST_RSHUF
void repeat_shuffle(CardDeck orig_deck, int k)
{
	//orig_deck contains a deck of cards, and it's size.

	//If (k ≤ 0), no shuffling, print the only possible outcome.
		//printDeck(orig_deck); and return
		//TIP: Print only the results obtained after k rounds of shuffling
	// call shuffle(orig_deck);
	if (k <= 0){
		printDeck(orig_deck);
		return;
	}

	shuffle(orig_deck, k);
	// TIP: In interleave(…), when the newly shuffled deck is complete,
		//you will perform another k-1 rounds of shuffling with the new deck.
}
#endif
