#include <stdlib.h> // for free()
#include "board.h"
#include "tools/display_utils.h" // for right_pad, center_pad, LEFT_PAD, RIGHT_PAD

// Modify the score board directly by using a pointer
void populate_board_data(Board *board, char *min_score, char *reward, char *current_score,
                          char *played_hand, char *level, char *chips, char *mult,
                          char *hands, char *discards, char *money, char *ante, char *round) {
    board->color[7][5] = right_pad(min_score, board->art[7]);
    board->color[8][5] = right_pad(reward, board->art[8]);
    board->color[14][3] = right_pad(current_score, board->art[14]);

    board->color[19][3] = center_pad(played_hand, level, board->art[19], LEFT_PAD);
    board->color[19][4] = center_pad(played_hand, level, board->art[19], RIGHT_PAD);
    board->color[21][3] = center_pad(chips, mult, board->art[21], LEFT_PAD);
    board->color[21][8] = center_pad(chips, mult, board->art[21], RIGHT_PAD);

    board->color[26][5] = right_pad(hands, board->art[26]);
    board->color[27][5] = right_pad(discards, board->art[27]);
    board->color[31][5] = right_pad(money, board->art[31]);
    board->color[32][5] = right_pad(ante, board->art[32]);
    board->color[33][5] = right_pad(round, board->art[33]);
}

/*
    ((uint) min_score > UINT_MAX) ? "N/A" : min_score;
    ((uint) current_score > UINT_MAX) ? "N/A" : current_score;
*/

// free the variables that used malloc() when done
void free_board_data(void) {
    free(small_blind.color[7][5]);
    free(small_blind.color[8][5]);
    free(small_blind.color[14][3]);
    free(small_blind.color[19][3]);
    free(small_blind.color[19][4]);
    free(small_blind.color[21][3]);
    free(small_blind.color[21][8]);
    free(small_blind.color[26][5]);
    free(small_blind.color[27][5]);
    free(small_blind.color[31][5]);
    free(small_blind.color[32][5]);
    free(small_blind.color[33][5]);
}
