#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
    struct student *next;
};

struct student* insert(struct student *head) {
    struct student *temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter roll and name: ");
    scanf("%d %s", &temp->roll, temp->name);
    temp->next = head;
    return temp;
}

void display(struct student *head) {
    while (head != NULL) {
        printf("Roll: %d Name: %s\n", head->roll, head->name);
        head = head->next;
    }
}

int main() {
    struct student *head = NULL;
    int n = 2;

    for (int i = 0; i < n; i++)
        head = insert(head);

    display(head);
    return 0;
}
