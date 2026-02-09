#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff, exp;
    struct poly *next;
};

struct poly* insert(struct poly *head, int c, int e) {
    struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
    temp->coeff = c;
    temp->exp = e;
    temp->next = head;
    return temp;
}

struct poly* addPoly(struct poly *p1, struct poly *p2) {
    struct poly *result = NULL;

    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(struct poly *p) {
    while (p != NULL) {
        printf("%dx^%d ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct poly *p1 = NULL, *p2 = NULL, *sum;

    p1 = insert(p1, 5, 2);
    p1 = insert(p1, 4, 1);

    p2 = insert(p2, 5, 1);
    p2 = insert(p2, 2, 0);

    sum = addPoly(p1, p2);

    display(sum);
    return 0;
}
