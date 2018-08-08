/***********************************
 * Sidharth Sengupta
 * Random Test 2 for Assignment 4
 * Tests the smithy card
 ************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define NUMTRIES 100

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
    int c, x, i, j;  
    int handBefore;  
	srand(time(0));
	
    printf("Random Card Test 2: Testing Smithy\n");

	for(i = 0; i < NUMTRIES; i++) {

		printf("Iteration %d\n", i + 1);
        initializeGame(numPlayer, k, seed, &G);
		x = 1;
	
		c = (rand() % 8) + 3;
        G.deckCount[0] = c;
		handBefore = G.handCount[0];

        for(j = 0; j < c; j++) 
            G.deck[0][j] = k[rand() % 10];

        G.hand[0][0] = smithy;
        playCard(0, 0, 0, 0, &G);

		if(asserttrue(handBefore + 3, G.handCount[0], "Hand Count Failed") == 0 && x != 0)
            x = 0;

		if(x)
            printf("Random Card Test 2 Iteration %d Successfully Completed\n\n", i + 1); 
        else {
            printf("Random Card Test 2 Iteration %d Failed\n", i + 1); 
            printf("Expected hand count: %d, actual: %d\n\n", handBefore + 3, G.handCount[0]);
        }   
    }   
    return 0;
}
