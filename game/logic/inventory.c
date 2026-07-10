#include <stdlib.h> // for malloc
#include "inventory.h"

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

void set_inventory(Card arr[]) {
    int inventory_length = 4; // need to make it dynamic

    for (int i = 0; i < inventory_length; i++) {
        // if Joker card, and own more than one
        if ((arr[i].type == JOKER) && (arr[i].owned > 0)) {
            // how to handle enhance joker cards?
        }
    }
}

void set_deck(void) {
    // set deck
}
