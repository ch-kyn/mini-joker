#include <stdio.h>
#include "input.h"
#include "round.h"
#include "screen.h"

// runs the blocking command loop (q = quit, t = test render, a = print hi)
void run_input_loop(Card inventory[], int inventory_count, Card deck[]) {
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
                update_round(inventory, inventory_count, deck, "1");
            } else {
                printf("inventory too small to test index 3\n");
            }
        }

        // wait on letter 'a', clear screen, then print "hi"
        if (input == 'a' || input == 'A') {
            clear_screen();
            printf("hi\n");
        }
    }
}
