#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Move last node to front
void moveLastToFront(struct Node** head) {
    // If list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node* secLast = NULL;
    struct Node* last = *head;

    // Traverse to find last and second last
    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }

    // Change links
    secLast->next = NULL;
    last->next = *head;
    *head = last;
}

// Insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Original List:\n");
    display(head);

    moveLastToFront(&head);

    printf("After Moving Last Node to Front:\n");
    display(head);

    return 0;
}
