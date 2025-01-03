#ifndef CARDS_H
#define CARDS_H

#include "colors.h" // make color constants available

#define CARD_LENGTH 10
// magic number defining that a line can have no more than 8 colors (escapes included)
#define MAX_COLORS 16 

extern const char* FIBONACCI[CARD_LENGTH];
extern const char* C_FIBONACCI[CARD_LENGTH][MAX_COLORS];
extern const char* DNA[CARD_LENGTH];
extern const char* C_DNA[CARD_LENGTH][MAX_COLORS];
extern const char* FOUR_FINGERS[CARD_LENGTH];
extern const char* C_FOUR_FINGERS[CARD_LENGTH][MAX_COLORS];

#endif