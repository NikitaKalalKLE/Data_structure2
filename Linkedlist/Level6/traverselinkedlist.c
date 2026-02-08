#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert node at end
struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeofstruct Node);
    newNode->data = data;

    // Empty list
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Traverse circular linked list
void traverse(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    printf("Circular Linked List elements:\n");
    traverse(head);

    return 0;
}
