#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n1, n2, value;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("\nEnter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    printf("\nList 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    head1 = concatenate(head1, head2);

    printf("\nConcatenated List: ");
    display(head1);

    return 0;
}
