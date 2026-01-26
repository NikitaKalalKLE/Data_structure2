#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop found
    if (slow != fast)
        return;

    // Step 2: Find start of loop
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove loop
    fast->next = NULL;
}
