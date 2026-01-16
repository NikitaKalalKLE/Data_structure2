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

// Delete all occurrences
struct Node* deleteAllOccurrences(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    // Remove matching nodes at beginning
    while (head != NULL && head->data == key) {
        curr = head;
        head = head->next;
        free(curr);
    }

    curr = head;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
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
    int key;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 10);
    head = insertEnd(head, 30);
    head = insertEnd(head, 10);

    printf("Original List:\n");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    head = deleteAllOccurrences(head, key);

    printf("\nList after deletion:\n");
    display(head);

    return 0;
}
