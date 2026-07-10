#include <stdio.h>
#include "screen.h"

void clear_screen(void) {
    printf("\033[H\033[J");
}
