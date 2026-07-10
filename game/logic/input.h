#ifndef INPUT_H
#define INPUT_H

#include "design/items.h" // for Card type

// runs the blocking command loop (q = quit, t = test render, a = print hi)
// returns when the user quits ('q')
void run_input_loop(Card inventory[], int inventory_count, Card deck[]);

#endif // INPUT_H
