#include "round.h"
#include "board.h"
#include "tools/display_utils.h" // for display_interface

// add more arguments later
void update_round(Card inventory[], int inventory_size, Card deck[], char *round) {
    // for testing purposes; need to calculate the values, cast them to strings, then store and pass the variables as parameters
    // need to remove the hard-coded small-blind table
    populate_board_data(&small_blind, "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", round);
    display_interface(inventory, inventory_size, deck);
    free_board_data();
}
