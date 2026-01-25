#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int detectLoop(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast) {
            return 1;   // Loop detected
        }
    }
    return 0;   // No loop
}
