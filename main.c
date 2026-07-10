#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include "design/items.h"
#include "tools/display_utils.h"
#include "tools/linked_list.h"
#include "game/render/screen.h"
#include "game/render/board.h"
#include "game/logic/inventory.h"
#include "game/render/round.h"
#include "game/logic/input.h"

typedef unsigned int uint;

typedef enum {
    FOIL,        // +50 chips
    HOLOGRAPHIC, // +10 Mult
    POLYCHROME,  // X1.5 Mult
    NEGATIVE     // +1 Joker slot; add a limit of it -> needs to be an alternative so this can be used for playing cards too?
} Edition;

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

    // interactive test loop (q = quit, t = test render, a = print hi)
    run_input_loop(inventory, inventory_count, playing_deck);

    free(inventory);
    free(collection);
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