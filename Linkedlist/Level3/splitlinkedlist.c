#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to split the list
void splitList(struct Node *head,
               struct Node **head1,
               struct Node **head2) {

    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;      // first half
    *head2 = slow;      // second half

    if (prev != NULL)
        prev->next = NULL;  // break the list
}

// Utility to print list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
