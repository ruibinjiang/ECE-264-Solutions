// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void rec_me(CardDeck, char *, int , char *, int, int, int, int );
#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks
  for(int i = 0; i<orig_deck.size - 1; i++){
		strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		upper_deck[i].size = i+1;
		strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
		lower_deck[i].size = orig_deck.size -i - 1;
	}
	// starting from i = 0 -> size-1 copying into upper deck and lower decks
		// For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		// Update the size of the upper and lower decks after copying each element.
			// For example: upper_deck[i].size = i+1;

		// Similarly perform the string copy, and size update operation on the lower deck.
			//For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
		    // For example: lower_deck[i].size = orig_deck.size -i - 1;
	return;
}
#endif

#ifdef TEST_INTER
void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
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
    // Follow instructions in the README, to understand the working of the recursive function.
    // Use print_deck(…) to print each resulting order.
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
		rec_me(deck_fnl, upper, up_i, lower, low_i, fnl_i, upper_deck.size, lower_deck.size);
    free(upper);
    free(lower);
		return;
}

void rec_me(CardDeck deck_fnl, char * upper, int up_i, char *lower, int low_i, int fnl_i, int upper_size, int lower_size){
	if (up_i >= upper_size){
		for(int i = low_i; i < lower_size; ++i){
			deck_fnl.cards[fnl_i] = lower[i];
			++fnl_i;
		}
		print_deck(deck_fnl);
		return;
	}
	if (low_i >= lower_size){
		for(int i = up_i; i < upper_size; ++i){
			deck_fnl.cards[fnl_i] = upper[i];
			++fnl_i;
		}
		print_deck(deck_fnl);
		return;
	}

	deck_fnl.cards[fnl_i] = upper[up_i];
	rec_me(deck_fnl, upper, up_i+1, lower, low_i, fnl_i+1, upper_size, lower_size);

	deck_fnl.cards[fnl_i] = lower[low_i];
	rec_me(deck_fnl, upper, up_i, lower, low_i+1, fnl_i+1, upper_size, lower_size);
}
#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
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
			interleave(upper_deck[i],lower_deck[i]);
		}
    // free memory allocated to upper and lower deck.
		free(upper_deck);
		free(lower_deck);
}
#endif
