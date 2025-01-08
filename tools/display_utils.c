
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utf8proc.h>
#include "../design/items.h"
#include "display_utils.h"

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

// Check how many placeholders there are per line, and include neccessary insertions accordingly
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

int print_board_line(const char* board[BOARD_LENGTH], char* colors[BOARD_LENGTH][12], int num_line) {
    if (num_line >= 0 && num_line < 37) {
        int num_colors = colors_per_line(board[num_line]);

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
