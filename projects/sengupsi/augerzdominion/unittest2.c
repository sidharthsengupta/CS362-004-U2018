/******************
 * Sidharth Sengupta
 * Unit Test 2 for Assignment 3 (CS362)
 * Tests supplyCount() function in dominion.c
 *********************************************/

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
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, 
				 smithy, village, baron, great_hall};
	struct gameState G;
	int r, x = 1;

	printf("Unit Test 2: TESTING supplyCount()\n");
	r = initializeGame(numPlayer, k, seed, &G);
	
	// Test 1 ////////////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing supply count with initial curse count\n");
	#endif

	r = supplyCount(curse, &G);
	if(asserttrue(r, 10, "Test 1 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: 10\n");
	#endif 

	// Test 2 ////////////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing supply count with initial treasure_map count\n");
	#endif

	r = supplyCount(treasure_map, &G);
	if(asserttrue(r, -1, "Test 2 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: -1\n");
	#endif 

	// Test 3 ////////////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing supply count with changed copper count\n");
	#endif

	G.supplyCount[copper] = 123;
	r = supplyCount(copper, &G);
	if(asserttrue(r, 123, "Test 3 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: 123\n");
	#endif 
	
	if(x)
		printf("Unit Test 2 Successfully Completed\n\n");
	else
		printf("\n");
	
	return 0;
}
