/***************************************
 * Sidharth Sengupta
 * Card Test 1 for Assignment 3 (CS362)
 * Tests the adventurer card
 ***************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int asserttrue(int a, int b, char *error) {
	if(a != b) {
		printf("%s\n", error);
		return 0;
	}
	return 1;
}

int main() {

	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
				 remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int r, x = 1; 
	
	r = initializeGame(numPlayer, k, seed, &G);
	
	printf("Card Test 1: TESTING adventurer\n");

	G.deckCount[0] = 0;
	G.discardCount[0] = 5;
	G.discard[0][0] = copper;
	G.discard[0][1] = copper;
	G.discard[0][2] = copper;
	G.discard[0][3] = copper;
	G.discard[0][4] = copper;
	G.hand[0][0] = adventurer;
	playCard(0, 0, 0, 0, &G);
	
	if(asserttrue(6, G.handCount[0], "Hand Count Failed") == 0 && x != 0)
		x = 0; 
	if(asserttrue(3, G.deckCount[0], "Deck Count Failed") == 0 && x != 0)
		x = 0; 
	if(x)
		printf("Card Test 1 Successfully Completed\n\n");
	else {
		printf("Card Test 1 Failed\n");
		printf("Expected hand count: 6, actual: %d\n", G.handCount[0]);
		printf("Expected deck count: 3, actual: %d\n\n", G.deckCount[0]);
	}	
	return 0;
}
