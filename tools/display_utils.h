#ifndef DISPLAY_UTILS_H
#define DISPLAY_UTILS_H

#include <utf8proc.h>
#include "../design/items.h"

typedef enum {
    LEFT_PAD,
    RIGHT_PAD
} Padding;

size_t utc8_length(const char* line);
int colors_per_line(const char* line);
int print_card_line(const char* card[CARD_LENGTH], const char* colors[CARD_LENGTH][MAX_COLORS], int num_line);
int print_board_line(const char* board[BOARD_LENGTH], char* colors[BOARD_LENGTH][12], int num_line);
char* right_pad(char* string, const char* line);
char* center_pad(char* string1, char* string2, const char* line, Padding alignment);

#endif