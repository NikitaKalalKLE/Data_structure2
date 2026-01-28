#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swapNodes(struct Node **head, int x, int y) {
    if (x == y)
        return;

    struct Node *prevX = NULL, *currX = *head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *prevY = NULL, *currY = *head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY)
        return;

    if (prevX)
        prevX->next = currY;
    else
        *head = currY;

    if (prevY)
        prevY->next = currX;
    else
        *head = currX;

    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}
