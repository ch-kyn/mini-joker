#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utf8proc.h>
#include "../design/items.h"
#include "display_utils.h"

// checks length of a UTC-8 string; does not take into account non-composed characters
size_t utc8_length(const char* line) {
    size_t count = 0; // keeps track of the number of Unicode code points
    const unsigned char* p = (const unsigned char*) line;
    utf8proc_int32_t code_point;

    // while trying to decode a code point starting from 'p' of unknown length, return the number used to encode the current code point if successfull
    // done when encountering null terminator
    while (*p) {
        int bytes = utf8proc_iterate(p, -1, &code_point);
        if (bytes < 0) {
            break; // if error in UTF-8 decording
        }
        p += bytes;
        count++;
    }

    return count;
}

// find out how many colors (escapes included) there are per line of a card by locating "%s"
int placeholders_per_line(const char* line) {
    int count = 0;
    int length = strlen(line);

    for (int i = 0; i < length - 1; i++) {
        if (line[i] == '%' && line[i + 1] == 's') {
                count++;
        }
    }

    return count;
}

// check how many placeholders there are per line, and include neccessary insertions accordingly
int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS_CARD], int num_line) {
    if (num_line >= 0 && num_line < CARD_LENGTH) {
        int num_colors = placeholders_per_line(card[num_line]); 

        char output[256] = {0};
        sprintf(output, card[num_line], 
            colors[num_line][0], colors[num_line][1], 
            (num_colors > 2) ? colors[num_line][2] : "", 
            (num_colors > 3) ? colors[num_line][3] : "",
            (num_colors > 4) ? colors[num_line][4] : "",
            (num_colors > 5) ? colors[num_line][5] : "",
            (num_colors > 6) ? colors[num_line][6] : "",
            (num_colors > 7) ? colors[num_line][7] : "",
            (num_colors > 8) ? colors[num_line][8] : "",
            (num_colors > 9) ? colors[num_line][9] : "",
            (num_colors > 10) ? colors[num_line][10] : "",
            (num_colors > 11) ? colors[num_line][11] : "",
            (num_colors > 12) ? colors[num_line][12] : "",
            (num_colors > 13) ? colors[num_line][13] : "",
            (num_colors > 14) ? colors[num_line][14] : "",
            (num_colors > 15) ? colors[num_line][15] : "",
            (num_colors > 16) ? colors[num_line][16] : "",
            (num_colors > 17) ? colors[num_line][17] : "",
            (num_colors > 18) ? colors[num_line][18] : "",
            (num_colors > 19) ? colors[num_line][19] : "",
            (num_colors > 20) ? colors[num_line][20] : "",
            (num_colors > 21) ? colors[num_line][21] : "",
            (num_colors > 22) ? colors[num_line][22] : "",
            (num_colors > 23) ? colors[num_line][23] : "");

            printf("%s", output);
    }

    return 0;
}

int print_board_line(const char* board[BOARD_LENGTH], char* colors[BOARD_LENGTH][MAX_COLORS_BOARD], int num_line) {
    if (num_line >= 0 && num_line < 37) {
        int num_colors = placeholders_per_line(board[num_line]);

        char output[256] = {0};
        sprintf(output, board[num_line], 
            (num_colors > 0) ? colors[num_line][0] : "",
            (num_colors > 1) ? colors[num_line][1] : "",
            (num_colors > 2) ? colors[num_line][2] : "",
            (num_colors > 3) ? colors[num_line][3] : "",
            (num_colors > 4) ? colors[num_line][4] : "",
            (num_colors > 5) ? colors[num_line][5] : "",
            (num_colors > 6) ? colors[num_line][6] : "",
            (num_colors > 7) ? colors[num_line][7] : "",
            (num_colors > 8) ? colors[num_line][8] : "",
            (num_colors > 9) ? colors[num_line][9] : "",
            (num_colors > 10) ? colors[num_line][10] : "",
            (num_colors > 11) ? colors[num_line][11] : "");

            printf("%s", output);
    }

    return 0;
}

char* right_pad(char* string, const char* line) {
    int row_length = utc8_length(line);
    int input_length = strlen(string);

    // subtract the placeholders from the length of 'line'
    int trimmed_length = row_length - (placeholders_per_line(line) * 2);
    int space_qty = BOARD_WIDTH - trimmed_length - input_length;

    char* formatted_string = NULL;
    if (space_qty >= 0) {
        // allocate memory for formatted_string (space for string + spaces + null terminator)
        formatted_string = malloc(input_length + space_qty + 1);

        if (formatted_string != NULL) {
            // copy the original string to the formatted string, and fill the remaining space with spaces
            sprintf(formatted_string, "%s", string);
            // points to the start of the string, then move the pointer past the original string
            memset(formatted_string + input_length, ' ', space_qty);
            formatted_string[input_length + space_qty] = '\0'; // add null terminator
        } else {
            return NULL;
        }
    } else {
        // space padding not needed; needs to add more manual checks later
        formatted_string = malloc(input_length + 1);
        if (formatted_string) {
            memcpy(formatted_string, string, input_length + 1);
        }
    }

    return formatted_string;
}

char* center_pad(char* string1, char* string2,  const char* line, Padding alignment) {
    int row_length = utc8_length(line);
    int input_length1 = strlen(string1);
    int input_length2 = strlen(string2);

    int trimmed_length = row_length - (placeholders_per_line(line) * 2);

    int space_qty = BOARD_WIDTH - trimmed_length - (input_length1 + input_length2);
    int space_left = space_qty / 2;
    int space_right = space_qty - space_left;

    char* formatted_string = NULL;

    if (alignment == LEFT_PAD) {
        formatted_string = malloc(input_length1 + space_left + 1);

        if (formatted_string == NULL) {
            return NULL;
        }

        memset(formatted_string, ' ', space_left);
        sprintf(formatted_string + space_left, "%s", string1);
        formatted_string[input_length1 + space_left] = '\0';

    } else if (alignment == RIGHT_PAD) {
        formatted_string = malloc(input_length2 + space_right + 1);

        if (formatted_string == NULL) {
            return NULL;
        }

        sprintf(formatted_string, "%s", string2);
        memset(formatted_string + input_length2, ' ', space_right);
        formatted_string[input_length2 + space_right] = '\0';
    }

    return formatted_string;
}

void display_interface(Card inventory[], int inventory_size, Card deck[]) {
    // print the height of the board plus add two additional lines at the bottom
    for (int i = 0; i < BOARD_LENGTH + 2; i++) {
        print_board_line(small_blind.art, small_blind.color, i);
        // space out the scoring board from the cards
        printf("  ");

        // iterate over the inventory of cards
        for (int j = 0; j < inventory_size; j++) {
            // skip first line to create white space
            if (i == 0) {
                printf("");
            // numerate locations of cards if need to swap etc.
            } else if (i == 1) {
                int index = 'a' + j;

                if (inventory[j].type == JOKER) {
                    printf("[%c]           ", index);
                    
                    if (j < 2) {
                        printf("\b\b\b"); // move back cursor for next card
                    }
                    
                // need to add a check for if no jokers before consumables
                } else if ((inventory[j].type == TAROT || inventory[j].type == PLANET) && (inventory[j - 1].type == JOKER)) {
                    printf("    [%c]", index);
                } else {
                    // add four space to the left to make up for the seperation between jokers and consumables
                    printf("       [%c]", index);
                }
            } else if (i < CARD_LENGTH + 2) {
                if (inventory[j].type == JOKER) {
                    print_card_line(inventory[j].art, inventory[j].color, i - 2); // print the i-th row of the j-th card's art                        
                    printf(" ");

                    // am hard-coding this, ignore for now
                    // I would need to calculate how many jokers there are, and adapt the \b depending on how many i have
                    if (j < 2) {
                        // need to make it more dynamic yaya
                        printf("\b\b\b");
                    }
                }
                // printf("CCCC");
                if ((inventory[j].type == TAROT || inventory[j].type == PLANET) && (inventory[j - 1].type == JOKER)) {
                    printf("    ");
                }

                if (inventory[j].type == TAROT || inventory[j].type == PLANET) {
                    // printf("    ");
                    print_card_line(inventory[j].art, inventory[j].color, i - 2);
                    
                    if (j < inventory_size - 1) {
                        printf("\b\b\b"); // Move back cursor for next card
                    }
                }
            }                
        }

        // had to move it here as '\b' messed it up
        if (i == 35) { // need to create a 'check inventory size' function
            printf("x/y");
        }

        // iterate over playing cards; needs to be randomized
        for (int l = 0; l < 8; l++) {
            if (i >= 26 && i <= 34) {
                print_card_line(deck[l].art, deck[l].color, i - 26);
                printf(" ");
            } else if (i == 25) { // insert letters (change to later) one line before
                printf("[%i]           ", l + 1);
            }

            if (l < 7) { // prevent extra spacing after the last card
                printf("\b\b\b"); // Move the cursor back by 2 spaces to create overlap
            }
        }

        printf("\n");
    }
}