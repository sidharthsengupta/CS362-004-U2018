/***************************************
 * Sidharth Sengupta
 * Card Test 3 for Assignment 3 (CS362)
 * Tests the outpost card
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
    
    printf("Card Test 3: TESTING outpost\n");

    G.hand[0][0] = outpost;
    playCard(0, 0, 0, 0, &G);

	if(asserttrue(1, G.outpostPlayed, "Outpost Flag Failed") == 0 && x != 0)
        x = 0;  
    if(asserttrue(4, G.handCount[0], "Hand Count Failed") == 0 && x != 0)
        x = 0;  
    if(x)
        printf("Card Test 3 Successfully Completed\n\n");
    else {
        printf("Card Test 3 Failed\n");
        printf("Expected Outpost Flag Value: 1, actual: %d\n", G.outpostPlayed);
        printf("Expected hand count: 4, actual: %d\n\n", G.handCount[0]);
    }   
    return 0;
}
