/***************************************
 * Sidharth Sengupta
 * Card Test 4 for Assignment 3 (CS362)
 * Tests the village card
 ****************************************/

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
    
    printf("Card Test 4: TESTING village\n");

    G.hand[0][0] = village;
    playCard(0, 0, 0, 0, &G);
 
	if(asserttrue(5, G.handCount[0], "Hand Count Failed") == 0 && x != 0)
        x = 0;  
    if(asserttrue(2, G.numActions, "Action Count Failed") == 0 && x != 0)
        x = 0; 

    if(x)
        printf("Card Test 4 Successfully Completed\n\n");
    else {
        printf("Card Test 4 Failed\n");
        printf("Expected hand count: 5, actual: %d\n", G.handCount[0]);
        printf("Expected number of actions: 2, actual: %d\n\n", G.numActions);
    }   
    return 0;
}

