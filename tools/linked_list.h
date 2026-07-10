#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../design/items.h"

// create a Node structure for a double linked list that stores a card, and a pointer to both the previous and next pointer
typedef struct Node {
    Card card;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(Card card);
void appendNode(Node** head, Card card);
void printList(Node* head);
void freeList(Node *head);
void shiftNode(Node **head);
void deleteNode(Node **head, char* value);
#endif