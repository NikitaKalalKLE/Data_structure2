#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push */
void push(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

/* Pop */
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

/* Display */
void display() {
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(5);
    push(10);
    push(15);

    display();
    pop();
    display();

    return 0;
}
