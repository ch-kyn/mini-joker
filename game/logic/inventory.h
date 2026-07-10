#ifndef INVENTORY_H
#define INVENTORY_H

#include "design/items.h" // for Card type

// builds a flat array of owned cards from the full collection (caller must free() the result)
Card *ini_inventory(Card *collection, int num);

// placeholder for handling special inventory logic (e.g. joker editions)
void set_inventory(Card arr[]);

// placeholder for setting up the playing deck
void set_deck(void);

#endif // INVENTORY_H
