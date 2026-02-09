#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

/* Insert at end */
void insertEnd(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;

    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

/* Split into two halves */
void splitList(struct node *last,
               struct node **head1,
               struct node **head2) {
    struct node *slow = last->next;
    struct node *fast = last->next;

    while (fast->next != last->next &&
           fast->next->next != last->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = last->next;
    *head2 = slow->next;

    slow->next = *head1;
    fast->next = *head2;
}

/* Display */
void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) return;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);

    splitList(last, &head1, &head2);

    printf("First Half:\n");
    display(head1);

    printf("Second Half:\n");
    display(head2);

    return 0;
}
