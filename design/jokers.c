#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cards.h"

int colors_per_line(const char* line);
int print_card(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS]);
int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line);

int main(void) {
    print_card(FIBONACCI, C_FIBONACCI);
    print_card(DNA, C_DNA);
    print_card(FOUR_FINGERS, C_FOUR_FINGERS);
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

// Print each line of a card, with its colors
int print_card(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS]) {
    for (int i = 0; i < CARD_LENGTH; i++) {
        int num_colors = colors_per_line(card[i]); 

        // sligh abomination, but at least it works T_T
        switch (num_colors) {
            case 2:
                printf(card[i], colors[i][0], colors[i][1]);
                break;
            case 4:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3]);
                break;
            case 6:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5]);
                break;
            case 8:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5], colors[i][6], colors[i][7]);
                break;
            case 10:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5], colors[i][6], colors[i][7], colors[i][8], colors[i][9]);
                break;
            case 12:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5], colors[i][6], colors[i][7], colors[i][8], colors[i][9], colors[i][10], colors[i][11]);
                break;
            case 14:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5], colors[i][6], colors[i][7], colors[i][8], colors[i][9], colors[i][10], colors[i][11], colors[i][12], colors[i][13]);
                break;
            case 16:
                printf(card[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3], colors[i][4], colors[i][5], colors[i][6], colors[i][7], colors[i][8], colors[i][9], colors[i][10], colors[i][11], colors[i][12], colors[i][13], colors[i][14], colors[i][15]);
                break;
        }    

        printf("\n");
    }

    return 0;
}

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

        printf("\n");
    }

    return 0;
}