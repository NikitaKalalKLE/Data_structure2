#include <stdio.h>

int main() {
    int scores[100], rank[100];
    int n, i, j;

    printf("Enter number of players: ");
    scanf("%d", &n);

    printf("Enter scores:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    // Ranking logic
    for (i = 0; i < n; i++) {
        rank[i] = 1;
        for (j = 0; j < n; j++) {
            if (scores[j] > scores[i]) {
                rank[i]++;
            }
        }
    }

    printf("\nScores\tRank\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", scores[i], rank[i]);
    }

    return 0;
}
