#include <stdio.h>
#include <stdlib.h>

struct song {
    char name[30];
    struct song *next;
};

struct song *last = NULL;

void addSong(char *name) {
    struct song *temp = (struct song *)malloc(sizeof(struct song));
    strcpy(temp->name, name);

    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void play() {
    if (last == NULL) return;

    struct song *temp = last->next;
    do {
        printf("Playing: %s\n", temp->name);
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    addSong("Song A");
    addSong("Song B");
    addSong("Song C");

    play();
    return 0;
}
