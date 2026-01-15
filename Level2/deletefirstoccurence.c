#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of a value
struct Node* deleteFirstOccurrence(struct Node *head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // If first node contains the key
    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }

    // If key found
    if (curr->next != NULL) {
        struct Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    } else {
        printf("Value not found\n");
    }

    return head;
}

// Display list
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nLinked List: ");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printf("\nUpdated Linked List: ");
    display(head);

    return 0;
}
