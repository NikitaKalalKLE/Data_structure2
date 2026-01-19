#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Copy linked list
struct Node* copyList(struct Node *head) {
    if (head == NULL)
        return NULL;

    struct Node *newHead = NULL;
    struct Node *temp = head;

    while (temp != NULL) {
        insertEnd(&newHead, temp->data);
        temp = temp->next;
    }

    return newHead;
}

// Display list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // Create first list
    insertEnd(&head1, 10);
    insertEnd(&head1, 20);
    insertEnd(&head1, 30);

    printf("Original List:\n");
    display(head1);

    // Copy list
    head2 = copyList(head1);

    printf("Copied List:\n");
    display(head2);

    return 0;
}
