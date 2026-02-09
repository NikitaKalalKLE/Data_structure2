#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Create circular linked list */
struct node* createCLL(int n) {
    struct node *last = NULL, *temp;

    for (int i = 1; i <= n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = i;

        if (last == NULL) {
            last = temp;
            last->next = last;
        } else {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }
    return last;
}

/* Josephus Logic */
int josephus(int n, int k) {
    struct node *last = createCLL(n);
    struct node *ptr = last, *prev;

    while (ptr->next != ptr) {
        for (int count = 1; count < k; count++) {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }

    int result = ptr->data;
    free(ptr);
    return result;
}

int main() {
    int n = 7, k = 3;

    printf("Josephus Position = %d\n", josephus(n, k));

    return 0;
}
