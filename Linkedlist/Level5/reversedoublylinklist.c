#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void reverse_dll() {
    struct node *current = head;
    struct node *temp = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev after swap)
        current = current->prev;
    }

    // Update head
    if (temp != NULL) {
        head = temp->prev;
    }

    printf("Doubly linked list reversed\n");
}
