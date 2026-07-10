#ifndef ITEMS_H
#define ITEMS_H

#include "colors.h" // make color constants available

#define CARD_LENGTH 9
// magic number defining that a line can have no more than 10 colors (escapes included)
#define MAX_COLORS_CARD 24
#define MAX_COLORS_BOARD 12
#define BOARD_WIDTH 35
#define BOARD_LENGTH 36

// store all jokers in an array
#define ALL_JOKERS 3

// four types of cards within the game
typedef enum {
    PLAYING,
    JOKER,
    PLANET,
    TAROT
} CardType;

// custom data type to hold information and styling of a Card (probably needs to be expanded later)
    // add 'rarity'
typedef struct {
    CardType type;
    char* name;
    const char* art[CARD_LENGTH];
    const char* color[CARD_LENGTH][MAX_COLORS_CARD]; // its associated colors per line
    union {
        struct {
            int buy_price;
            int sell_price;
            int owned;
        };
    };
} Card;

typedef struct {
    const char* art[BOARD_LENGTH];
    char* color[BOARD_LENGTH][MAX_COLORS_BOARD];
} Board;

typedef struct {
    int round;
    int actions_taken;
    int inventory_size;
    Card* inventory;
    int deck_size;
    Card* deck;
} GameState;

extern Board small_blind;

extern Card fibonacci;
extern Card dna;
extern Card four_fingers;
extern Card jack_d;
extern Card queen_d;
extern Card ace_d;

extern Card tarot_test;

#endif