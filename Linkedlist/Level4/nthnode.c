#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void nthFromEnd(struct Node* head, int n) {
    struct Node *fast = head, *slow = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("n is greater than the number of nodes\n");
            return;
        }
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    printf("Nth node from end is: %d\n", slow->data);
}
