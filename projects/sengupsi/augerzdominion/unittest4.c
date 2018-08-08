/****************************************
 * Sidharth Sengupta
 * Unit Test 4 for Assigment 3 (CS362)
 * Tests scoreFor function from dominion.c
 *****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

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

	printf("Unit Test 4: Testing scoreFor()\n");

	// Test 1 ////////////////////////////////////
	
	#if(NOISY_TEST == 1)
		printf("Testing first player score before game has started\n");
	#endif

	r = scoreFor(0, &G);
	if(asserttrue(r, 3, "Test 1 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned Value: %d, Expected: 3\n", r);
	#endif

	// Test 2 ////////////////////////////////////
	
	#if(NOISY_TEST == 1)
		printf("Testing second player score before game has started\n");
	#endif

	r = scoreFor(1, &G);
	if(asserttrue(r, 3, "Test 2 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned Value: %d, Expected: 3\n", r);
	#endif
	
	// Test 3 ////////////////////////////////////
	
	#if(NOISY_TEST == 1)
		printf("Testing first player score after adding cards to their deck/discard\n");
	#endif
	
	G.discardCount[0] += 3;
	G.discard[0][0] = duchy;
	G.discard[0][1] = duchy;
	G.discard[0][2] = duchy;
	G.deckCount[0] += 3;
	G.deck[0][5] = province;
	G.deck[0][6] = province;
	G.deck[0][7] = province;
	
	r = scoreFor(0, &G);
	if(asserttrue(r, 30, "Test 3 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned Value: %d, Expected: 30\n", r);
	#endif

	if(x) 
		printf("Unit 4 Tests Successfully Completed\n\n");
	else
		printf("\n");

	return 0;
}
