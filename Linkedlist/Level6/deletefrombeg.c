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

/* Delete from beginning */
void deleteBeg() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;

    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        last->next = temp->next;
        free(temp);
    }
}

/* Delete from end */
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;

    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last)
            temp = temp->next;

        temp->next = last->next;
        free(last);
        last = temp;
    }
}

/* Display */
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    deleteBeg();
    display();

    deleteEnd();
    display();

    return 0;
}
