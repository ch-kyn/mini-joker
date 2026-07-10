#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "../design/items.h"

Node* createNode(Card card) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    if (newNode == NULL) {
        return NULL;
    }

    // using the Arrow operator to point to the structure
    newNode->card = card;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(Node** head, Card card) {
    Node* newNode = createNode(card);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->card.name);
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// try to delete a node at the beginning
// https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
void shiftNode(Node **head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteNode(Node **head, char* value) {
    if (*head == NULL) {
        return;
    }

    // comparing the strings of the names of a card, and deleting if it is
    if (strcmp((*head)->card.name, value) == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->card.name, value) == 0) {
            prev->next = temp->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return;
}

