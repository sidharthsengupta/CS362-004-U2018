/***************************************************
 * Sidharth Sengupta
 * Unit Test 1 for Assignment 2 (CS362)
 * Tests compare() function in dominion.c
****************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <string.h>

// set noisy_test to 0 to remove prints from output
#define NOISY_TEST 1
#define MAXINT 2147483647
#define MININT -2147483648

int asserttrue(int a, int b, char *error) {	
	if(a != b) {
		printf("%s\n", error);
		return 0;
	}
	return 1;
}

int main() {

	void *a;	
	void *b;
	int a_int;
	int b_int;
	char a_char;
	char b_char;
	int r, x = 1;

	printf("Unit Test 1: TESTING compare():\n");

	// Test 1 ////////////////////////////////////////
	a_int = 0;
	b_int = 0;
	a = &a_int;
	b = &b_int;
	
	#if(NOISY_TEST == 1)
		printf("Testing values 0 and 0\n");
	#endif
	
	r = compare(a, b);
	if(asserttrue(r, 0, "Test 1 Failed") == 0 && x != 0)
		x = 0; 
	
	#if(NOISY_TEST == 1)
		printf("Return value: %d, Expected: 0\n");
	#endif

	// Test 2 ////////////////////////////////////////
	a_int = 1;
	b_int = MAXINT;
	a = &a_int;
	b = &b_int;
	
	#if(NOISY_TEST == 1)
		printf("Testing values 1 and 2147483647\n");
	#endif
	
	r = compare(a, b);
	if(asserttrue(r, -1, "Test 2 Failed") == 0 && x != 0)
		x = 0; 
	
	#if(NOISY_TEST == 1)
		printf("Return value: %d, Expected: -1\n");
	#endif

	// Test 3 ////////////////////////////////////////
	a_int = 1;
	b_int = MININT;
	a = &a_int;
	b = &b_int;
	
	#if(NOISY_TEST == 1)
		printf("Testing values 1 and -2147483648\n");
	#endif
	
	r = compare(a, b);
	if(asserttrue(r, 1, "Test 3 Failed") == 0 && x != 0)
		x = 0; 
	
	#if(NOISY_TEST == 1)
		printf("Return value: %d, Expected: 1\n");
	#endif
	
	// Test 4 ////////////////////////////////////////
	a_char = 'A';
	b_char = 'a';
	a = &a_char;
	b = &b_char;
	
	#if(NOISY_TEST == 1)
		printf("Testing values A(65) and a(97)\n");
	#endif
	
	r = compare(a, b);
	if(asserttrue(r, -1, "Test 4 Failed") == 0 && x != 0)
		x = 0; 
	
	#if(NOISY_TEST == 1)
		printf("Return value: %d, Expected: -1\n");
	#endif
	
	if(x)
		printf("Unit Test 1 Succesfully Completed\n\n");
	else
		printf("\n");
	return 0;
}
