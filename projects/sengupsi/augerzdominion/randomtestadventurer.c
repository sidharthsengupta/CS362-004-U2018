/***********************************
 * Sidharth Sengupta
 * Random Test 1 for Assignment 4
 * Tests Adventurer Card
 ***********************************/
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
    int t, x, i, j; 
	int size, c1, c2; 
    int treasureBefore, treasureAfter;  
	srand(time(0));

    printf("Random Card Test 1: Testing Adventurer\n");

    for(i = 0; i < NUMTRIES; i++) {

		printf("Iteration %d\n", i + 1);
        initializeGame(numPlayer, k, seed, &G);
		x = 1;       
 
		updateCoins(0, &G, 0);
        treasureBefore = G.coins;
        treasureAfter = treasureBefore;
        
		G.deckCount[0] = 0;
        G.discardCount[0] = size = (rand() % 9) + 2;
        
		for(j = 0; j < size; j++) 
            G.discard[0][j] = estate;

		c1 = rand() % size;
		c2 = rand() % size;
		while(c1 == c2) 
			c2 = rand() % size;

        t = rand() % 3;
        if(t == 0) {
			G.discard[0][c1] = copper;
            treasureAfter += 1;
        }
        else if(t == 1) {
			G.discard[0][c1] = silver;
            treasureAfter += 2;
        }
		else {
            G.discard[0][c1] = gold;
            treasureAfter += 3;
        }
        
        t = rand() % 3;
        if(t == 0) {
			G.discard[0][c2] = copper;
            treasureAfter += 1;
        }
        else if(t == 1) {
			G.discard[0][c2] = silver;
            treasureAfter += 2;
        }
		else {
            G.discard[0][c2] = gold;
            treasureAfter += 3;
        }
        
		G.hand[0][0] = adventurer;
		playCard(0, 0, 0, 0, &G);

        if(asserttrue(7, G.handCount[0], "Hand Count Failed") == 0 && x != 0)
            x = 0;
        if(asserttrue(size - 2, G.deckCount[0], "Deck Count Failed") == 0 && x != 0)
            x = 0;
        updateCoins(0, &G, 0);
        if(asserttrue(treasureAfter, G.coins, "Treasure Count Failed") == 0 && x != 0)
            x = 0;

        if(x)
            printf("Random Card Test 1 Iteration %d Successfully Completed\n\n", i + 1);
        else {
            printf("Random Card Test 1 Iteration %d Failed\n", i + 1);
            printf("Expected hand count: 7, actual: %d\n", G.handCount[0]);
            printf("Expected deck count: %d, actual: %d\n", size - 2, G.deckCount[0]);
            printf("Expected treasure count: %d, actual: %d\n\n", treasureAfter, G.coins);
        }
    }
	return 0;
}
