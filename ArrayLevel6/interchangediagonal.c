#include <stdio.h>

int main() {
    int n;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Interchange diagonals
    for (int i = 0; i < n; i++) {
        int temp = a[i][i];
        a[i][i] = a[i][n - 1 - i];
        a[i][n - 1 - i] = temp;
    }

    printf("\nMatrix after interchanging diagonals:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
