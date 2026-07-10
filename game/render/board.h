#ifndef BOARD_H
#define BOARD_H

#include "design/items.h" // for Board, Card types

// populates the given board's display fields (min score, reward, chips, mult, etc.)
void populate_board_data(Board *board, char *min_score, char *reward, char *current_score,
                          char *played_hand, char *level, char *chips, char *mult,
                          char *hands, char *discards, char *money, char *ante, char *round);

// frees all the malloc'd string fields on the small_blind board
void free_board_data(void);

#endif // BOARD_H
