#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <utf8proc.h>
#include "items.h"

typedef enum {
    RIGHT_PAD,
    LEFT_PAD
} Padding;

void clear_screen();
size_t utc8_length(const char* line);
char* right_pad(char* string, const char* line);
void start_blind(Card inventory[], int inventory_size, Card deck[], int blind);
int colors_per_line(const char* line);
int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line);
int print_ui_line(const char* ui[37], char* colors[37][12], int num_line);
char* center_pad(char* string1, char* string2, const char* line, Padding alignment);

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

// Checks length of a UTC-8 strin; does not take into account non-composed characters
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

char* right_pad(char* string, const char* line) {
    int row_length = utc8_length(line);
    int input_length = strlen(string);

    // subtract the placeholders from the length of 'line'
    int trimmed_length = row_length - (colors_per_line(line) * 2);
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

    int trimmed_length = row_length - (colors_per_line(line) * 2);

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

void start_blind(Card inventory[], int inventory_size, Card deck[], int blind) {
    if (blind == 0) {   
        // for testing purposes, should create a function later
        small_blind.color[7][5] = right_pad("300000", small_blind.art[7]);
        small_blind.color[8][5] = right_pad("$$$$$$$$$$$$$$$$$", small_blind.art[8]);
        small_blind.color[14][3] = right_pad("5000000000000000000000", small_blind.art[14]); 
        small_blind.color[19][3] = center_pad("Flush Five", "100000000000", small_blind.art[19], LEFT_PAD);
        small_blind.color[19][4] = center_pad("Flush Five", "100000000000", small_blind.art[19], RIGHT_PAD);
        small_blind.color[21][3] = center_pad("50", "50", small_blind.art[21], LEFT_PAD);
        small_blind.color[21][8] = center_pad("50", "50", small_blind.art[21], RIGHT_PAD);
        small_blind.color[26][5] = right_pad("4", small_blind.art[26]);
        small_blind.color[27][5] = right_pad("4", small_blind.art[27]);
        small_blind.color[31][5] = right_pad("4", small_blind.art[31]);
        small_blind.color[32][5] = right_pad("4", small_blind.art[32]);
        small_blind.color[33][5] = right_pad("4", small_blind.art[33]);
        small_blind.color[34][5] = right_pad("4", small_blind.art[34]);

        for (int i = 0; i < 38; i++) {
            // free(small_blind.color[14][3]);

            print_ui_line(small_blind.art, small_blind.color, i);                
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

        free(small_blind.color[7][5]);
        free(small_blind.color[8][5]);
        free(small_blind.color[14][3]);
        free(small_blind.color[19][3]);
        free(small_blind.color[19][4]);
        free(small_blind.color[21][3]);
        free(small_blind.color[21][8]);
        free(small_blind.color[26][5]);
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

int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line) {
    if (num_line >= 0 && num_line < CARD_LENGTH) {
        int num_colors = colors_per_line(card[num_line]); 

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
            (num_colors > 19) ? colors[num_line][19] : "");

            printf("%s", output);
    }

    return 0;
}

int print_ui_line(const char* ui[37], char* colors[37][12], int num_line) {
    if (num_line >= 0 && num_line < 37) {
        int num_colors = colors_per_line(ui[num_line]);

        char output[256] = {0};
        sprintf(output, ui[num_line], 
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