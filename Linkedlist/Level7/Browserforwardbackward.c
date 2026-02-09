#include <stdio.h>
#include <stdlib.h>

struct node {
    char url[50];
    struct node *prev, *next;
};

struct node *current = NULL;

void visit(char *url) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->url, url);
    temp->prev = current;
    temp->next = NULL;

    if (current)
        current->next = temp;
    current = temp;
}

void back() {
    if (current && current->prev)
        current = current->prev;
}

void forward() {
    if (current && current->next)
        current = current->next;
}

int main() {
    visit("google.com");
    visit("openai.com");
    back();
    printf("Current Page: %s\n", current->url);
    forward();
    printf("Current Page: %s\n", current->url);
    return 0;
}
