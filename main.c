#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "design/items.h"
#include "tools/display_utils.h"

typedef unsigned int uint;
void clear_screen();
void free_board_data();
void populate_board_data(Board* board, char* min_score, char* reward, char* current_score, char* played_hand, char* level, char* chips, char* mult, char* hands, char* discards, char* money, char* ante, char* round);
void start_blind(Card inventory[], int inventory_size, Card deck[], int blind);

// should probably use malloc() for this later... anyways
    // need to check for if jokers or tarot/planet
    // and its colors
    // card struct which says -> own = bool
    
char* test_deck[] = {
    // add later--make the creation of these cards more dynamic
        // use integers to access them instead?
};

// need to track game state

int main(void) {
    setlocale(LC_ALL, "en_US.UTF-8");
    clear_screen();
    // need to create a 'check inventory size' function
    // if copy > 1 ... include in inventory
    Card test_inventory[4] = {
        fibonacci, dna, four_fingers,
    }; 

    Card playing_deck[8] = {
        jack_d, jack_d, jack_d, jack_d, jack_d, jack_d, jack_d, jack_d
    };

    start_blind(test_inventory, 3, playing_deck, 0);
    
    /* char input;
    // while true, press x input
    while (1) {
        input = getchar();  // wait for user input

        if (input == 'q') {
            printf("Exiting the game.\n");
            break;
        }

        // render test, very unserious
        if (input == 't') {
            clear_screen();
            test_inventory[3] = fibonacci;
            start_blind(test_inventory, 4, 0);
        }
    } */

}

void clear_screen() {
    printf("\033[H\033[J");
}

// Modify the score board directly by using a pointer
void populate_board_data(Board* board, char* min_score, char* reward, char* current_score, char* played_hand, char* level, char* chips, char* mult, char* hands, char* discards, char* money, char* ante, char* round) {
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

// Free the variables that used'malloc()' when done
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

void start_blind(Card inventory[], int inventory_size, Card deck[], int blind) {
    if (blind == 0) {   
        // for testing purposes; need to calculate the values, cast them to strings, then store and pass the variables as parameters
        populate_board_data(&small_blind, "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", "4", "4");

        for (int i = 0; i < BOARD_LENGTH + 2; i++) {
            // free(small_blind.color[14][3]);

            print_board_line(small_blind.art, small_blind.color, i);                
            printf("  ");

            // iterate over the inventory of cards, skip first line to create white space
            for (int j = 0; j < inventory_size; j++) {
                if (i == 0) { // numerate locations of cards if need to swap etc. 
                    printf("");
                } else if (i == 1) {
                    printf("[%i]", j);
                    printf("            ");
                } else if (i < CARD_LENGTH + 2) {
                    print_card_line(inventory[j].art, inventory[j].color, i - 2); // print the i-th row of the j-th card's art
                    printf("  ");
                }
            }

            // had to move it here as '\b' messed it up
            if (i == 35) {
                printf("46/52");
            }

            // iterate over playing cards; needs to be randomized
            for (int l = 0; l < 8; l++) {
                if (i >= 26 && i <= 34) {
                    print_card_line(deck[l].art, deck[l].color, i - 26);
                    printf(" ");
                } else if (i == 25) { // insert letters (change to later) one line before
                    printf("[%i]", l);
                    printf("           ");
                }

                if (l < 7) {  // prevent extra spacing after the last card
                    printf("\b\b\b");  // Move the cursor back by 2 spaces to create overlap
                }
            }

            printf("\n");
        }

       free_board_data();
    }
}
