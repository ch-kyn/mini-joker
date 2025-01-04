#ifndef ITEMS_H
#define ITEMS_H

#include "colors.h" // make color constants available

#define CARD_LENGTH 10
// magic number defining that a line can have no more than 8 colors (escapes included)
#define MAX_COLORS 16 

// custom data type to hold information and styling of a Card (probably needs to be expanded later)
    // add 'rarity'
typedef struct {
    char* name;
    const char* art[CARD_LENGTH];
    const char* color[CARD_LENGTH][MAX_COLORS]; // its associated colors per line
    int buy_price;
    int sell_price;
    int owned;
} Card;

extern Card fibonacci;
extern Card dna;
extern Card four_fingers;

extern char* score_board_01[];
extern char* score_board_02[];
extern char* score_board_03[];

#endif