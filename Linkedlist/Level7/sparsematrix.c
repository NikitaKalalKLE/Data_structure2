#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, val;
    struct node *next;
};

struct node* insert(struct node *head, int r, int c, int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->row = r;
    temp->col = c;
    temp->val = v;
    temp->next = head;
    return temp;
}

void display(struct node *head) {
    printf("Row Col Value\n");
    while (head != NULL) {
        printf("%d   %d   %d\n", head->row, head->col, head->val);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;

    head = insert(head, 0, 1, 10);
    head = insert(head, 1, 2, 20);
    head = insert(head, 2, 0, 30);

    display(head);
    return 0;
}
