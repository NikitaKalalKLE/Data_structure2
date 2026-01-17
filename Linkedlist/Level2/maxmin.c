#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find max and min
void findMaxMin(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int max = head->data;
    int min = head->data;

    struct Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 25);
    head = insertEnd(head, 10);
    head = insertEnd(head, 40);
    head = insertEnd(head, 5);
    head = insertEnd(head, 30);

    printf("Linked List:\n");
    display(head);

    findMaxMin(head);

    return 0;
}
