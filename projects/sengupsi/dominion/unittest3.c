/************************************************
 * Sidharth Sengupta
 * Unit Test 3 for Assignment 3 (CS362)
 * Tests getCost function in dominion.c
 ***********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int asserttrue(int a, int b, char * error) {
	if(a != b) {
		printf("%s\n", error);
		return 0;
	}
	return 1;
}

int main() {

	int r, x = 1; 

	printf("Unit Test 3: Testing getCost()\n");
	
	// Test 1 //////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing curse card\n");
	#endif

	r = getCost(curse);
	if(asserttrue(r, 0, "Test 1 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: 0\n", r);
	#endif

	// Test 2 //////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing adventurer card\n");
	#endif

	r = getCost(adventurer);
	if(asserttrue(r, 6, "Test 2 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: 6\n", r);
	#endif
	
	// Test 3 //////////////////////////////////
	#if(NOISY_TEST == 1)
		printf("Testing unknown card\n");
	#endif

	r = getCost(274387);
	if(asserttrue(r, -1, "Test 3 Failed") == 0 && x != 0)
		x = 0;
	
	#if(NOISY_TEST == 1)
		printf("Returned value: %d, Expected: -1\n", r);
	#endif
		
	if(x)	
		printf("Unit Test 3 Successfully Completed\n\n");
	else
		printf("\n");

	return 0;
}
