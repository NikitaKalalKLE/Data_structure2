#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countLoopLength(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // Loop found
            int count = 1;
            fast = fast->next;

            while (fast != slow) {
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;   // No loop
}
