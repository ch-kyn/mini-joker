#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include "design/items.h"
#include "tools/display_utils.h"
#include "tools/linked_list.h"

typedef unsigned int uint;

typedef enum {
    FOIL,        // +50 chips
    HOLOGRAPHIC, // +10 Mult
    POLYCHROME,  // X1.5 Mult
    NEGATIVE     // +1 Joker slot; add a limit of it -> needs to be an alternative so this can be used for playing cards too?
} Edition;

void clear_screen();
Card *ini_inventory(Card *collection, int num);
void free_board_data();
void populate_board_data(Board *board, char *min_score, char *reward, char *current_score, char *played_hand, char *level, char *chips, char *mult, char *hands, char *discards, char *money, char *ante, char *round);
void update_round(Card inventory[], int inventory_size, Card deck[], char* round);

#define MAX_ANTE 4;
int required_score[] = {
    300, 450, 600, 800, 1200, 1600, 2000, 3000, 4000, 5000, 7500, 10000
};

// should probably use malloc() for this later... anyways
// need to check for if jokers or tarot/planet
// and its colors
// card struct which says -> own = bool

char *test_deck[] = {
    // add later--make the creation of these cards more dynamic
    // use integers to access them instead?
};

// add commands to play, discard, move, buy cards etc.
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");
    clear_screen();

    Node* head = NULL;
    appendNode(&head, fibonacci);
    appendNode(&head, dna);
    appendNode(&head, dna);
    appendNode(&head, four_fingers);
    printf("Linked List: ");
    printList(head);

    printf("Linked List: ");    
    deleteNode(&head, "DNA");
    printList(head);
    freeList(head);

    
    Card playing_deck[8] = {
        jack_d, jack_d, jack_d, jack_d, jack_d, jack_d, queen_d, ace_d
    };

    // cannot declare at compile time, so here is the array with all the Jokers within this bootleg
    Card collection_joker[ALL_JOKERS] = {
        fibonacci, dna, four_fingers
    };

    Card collection_item[] = {
        tarot_test
    };

    int num_jokers = ALL_JOKERS;
    int num_items = sizeof(collection_item) / sizeof(Card);
    int combined_size = num_jokers + num_items;

    // Allocate memory for the combined collection
    Card *collection = malloc(combined_size * sizeof(Card));
    if (collection == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }
    
    memcpy(collection, collection_joker, num_jokers * sizeof(Card));
    memcpy(collection + num_jokers, collection_item, num_items * sizeof(Card));

    // probably need to cache something here
    // and make it a function
    int inventory_count = 0;
    for (int i = 0; i < combined_size; i++) {
        if (collection[i].owned > 0) {
            inventory_count += collection[i].owned;
        }
    }

    Card *inventory = ini_inventory(collection, inventory_count);

    update_round(inventory, inventory_count, playing_deck, "1"); // hard-coding the round number

    // interactive test loop
    int input;
    while (1) {
        input = getchar();  // wait for user input

        if (input == 'q') {
            printf("Exiting the game.\n");
            break;
        }

        // render test, very unserious
        if (input == 't') {
            if (inventory_count > 3) {
                clear_screen();
                inventory[3] = fibonacci;
                update_round(inventory, inventory_count, playing_deck, "1");
            } else {
                printf("inventory too small to test index 3\n");
            }
        }
    }

    free(inventory);
    free(collection);
}

void clear_screen() {
    printf("\033[H\033[J");
}

/* void update_inventory(Card inventory[]) {
    Card inventory[] = malloc(sizeof(inventory));
} */

void set_inventory(Card arr[]) {
    int inventory_length = 4; // need to make it dynamic

    for (int i = 0; i < inventory_length; i++) {
        // if Joker card, and own more than one
        if ((arr[i].type == JOKER) && (arr[i].owned > 0)) {
            // how to handle enhance joker cards?
        }
    }
}

void set_deck() {
    // set deck
}

// Modify the score board directly by using a pointer
void populate_board_data(Board *board, char *min_score, char *reward, char *current_score, char *played_hand, char *level, char *chips, char *mult, char *hands, char *discards, char *money, char *ante, char *round) {
    board->color[7][5] = right_pad(min_score, board->art[7]);
    board->color[8][5] = right_pad(reward, board->art[8]);
    board->color[14][3] = right_pad(current_score, board->art[14]);

    board->color[19][3] = center_pad(played_hand, level, board->art[19], LEFT_PAD);
    board->color[19][4] = center_pad(played_hand, level, board->art[19], RIGHT_PAD);
    board->color[21][3] = center_pad(chips, mult, board->art[21], LEFT_PAD);
    board->color[21][8] = center_pad(chips, mult, board->art[21], RIGHT_PAD);

    board->color[26][5] = right_pad(hands, board->art[26]);
    board->color[27][5] = right_pad(discards, board->art[27]);
    board->color[31][5] = right_pad(money, board->art[31]);
    board->color[32][5] = right_pad(ante, board->art[32]);
    board->color[33][5] = right_pad(round, board->art[33]);
}

/*
    ((uint) min_score > UINT_MAX) ? "N/A" : min_score;
    ((uint) current_score > UINT_MAX) ? "N/A" : current_score;
*/

// free the variables that used'malloc()' when done
void free_board_data() {
    free(small_blind.color[7][5]);
    free(small_blind.color[8][5]);
    free(small_blind.color[14][3]);
    free(small_blind.color[19][3]);
    free(small_blind.color[19][4]);
    free(small_blind.color[21][3]);
    free(small_blind.color[21][8]);
    free(small_blind.color[26][5]);
    free(small_blind.color[27][5]);
    free(small_blind.color[31][5]);
    free(small_blind.color[32][5]);
    free(small_blind.color[33][5]);
}

Card *ini_inventory(Card *collection, int num) {
    // declare a pointer that points to a block of memory with the necessary size to store the owned cards
    Card *arr = malloc(num * sizeof(Card));

    if (!arr) return NULL;

    // just testing
    if (arr) {
        int current_index = 0; // need to keep track manually

        for (int i = 0; i < num; i++) {
            int qty = collection[i].owned;

            if (qty > 0) {
                for (int j = 0; j < qty; j++) {
                    arr[current_index] = collection[i];
                    current_index++;
                }
            }
        }
    }

    return arr;
}

// add more arguments later
void update_round(Card inventory[], int inventory_size, Card deck[], char* round) {
        // for testing purposes; need to calculate the values, cast them to strings, then store and pass the variables as parameters
        // need to remove the hard-coded small-blind table
        populate_board_data(&small_blind, "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", round);
        display_interface(inventory, inventory_size, deck);
        free_board_data();
}

/*
// remove card by shifting it out from index
void remove_card(Card cards[], int index, int arr_length) {
    for (int i = index; i < arr_length - 1; i++) {
        cards[i] = cards[i + 1];
    }
}

https://stackoverflow.com/questions/15821123/removing-elements-from-an-array-in-c/15821739#15821739
array_type *tmp = realloc(array, (array_length - 1) * sizeof(array_type));
if (tmp == NULL && array_length > 1) {
    exit(EXIT_FAILURE);    
}
array_length = array_length - 1;
array = tmp;
*/