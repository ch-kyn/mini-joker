#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "items.h"

void start_blind(Card inventory[], int inventory_size, int blind);
int colors_per_line(const char* line);
int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line);

// should probably use malloc() for this later... anyways
    // need to check for if jokers or tarot/planet
    // and its colors
    // card struct which says -> own = bool
    
char* test_deck[] = {
    // add later--make the creation of these cards more dynamic
        // use integers to access them instead?
};

int main(void) {
    // if copy > 1 ... include in inventory
    Card test_inventory[] = {
        fibonacci, dna, four_fingers
    }; 

    start_blind(test_inventory, 3, 0);
    // print_card(FOUR_FINGERS, C_FOUR_FINGERS);
}

void start_blind(Card inventory[], int inventory_size, int blind) {
    if (blind == 0) {   
        for (int i = 0; i < 12; i++) {
            // to make each card align from top to bottom, print necessary cards within 'inventory' line by line
            printf("%s", score_board_01[i]);
            printf("  ");

            // iterate over the inventory of cards
            for (int j = 0; j < inventory_size; j++) {
                if (i < CARD_LENGTH) {
                    print_card_line(inventory[j].art, inventory[j].color, i); // print the i-th row of the j-th card's art
                    printf("  ");
                }
            }

            printf("\n");
        }
    }
}


// Find out how many colors (escapes included) there are per line of a card by locating "%s"
int colors_per_line(const char* line) {
    int count = 0;
    int length = strlen(line);

    for (int i = 0; i < length - 1; i++) {
        if (line[i] == '%' && line[i + 1] == 's') {
                count++;
        }
    }

    return count;
}

// add a manual check to make sure color does not exceed maximum defined colors?

// utilize function to change for 'highest hand decrease' boss fight(?)
// Find the line of a card with the highest color count (escapes included)
/* int max_colors(const char* card[CARD_LENGTH]) {
    int max_count = 0;
    
    for (int i = 0; i < CARD_LENGTH; i++) {
        int check = colors_per_line(card[i]);

        if (max_count < check) {
            max_count = check;
        }
    }

    return max_count;
} */

int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line) {
    if (num_line >= 0 && num_line <= 9) {
        int num_colors = colors_per_line(card[num_line]); 

        switch (num_colors) {
            case 2:
                printf(card[num_line], colors[num_line][0], colors[num_line][1]);
                break;
            case 4:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3]);
                break;
            case 6:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5]);
                break;
            case 8:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5], colors[num_line][6], colors[num_line][7]);
                break;
            case 10:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5], colors[num_line][6], colors[num_line][7], colors[num_line][8], colors[num_line][9]);
                break;
            case 12:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5], colors[num_line][6], colors[num_line][7], colors[num_line][8], colors[num_line][9], colors[num_line][10], colors[num_line][11]);
                break;
            case 14:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5], colors[num_line][6], colors[num_line][7], colors[num_line][8], colors[num_line][9], colors[num_line][10], colors[num_line][11], colors[num_line][12], colors[num_line][13]);
                break;
            case 16:
                printf(card[num_line], colors[num_line][0], colors[num_line][1], colors[num_line][2], colors[num_line][3], colors[num_line][4], colors[num_line][5], colors[num_line][6], colors[num_line][7], colors[num_line][8], colors[num_line][9], colors[num_line][10], colors[num_line][11], colors[num_line][12], colors[num_line][13], colors[num_line][14], colors[num_line][15]);
                break;
        } 

        // printf("\n");
    }

    return 0;
}