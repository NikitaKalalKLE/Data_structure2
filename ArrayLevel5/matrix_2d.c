#include <stdio.h>

int main() {
    int a[10][10], i, j, r, c;

    // Read number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Read matrix elements
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Print matrix
    printf("Matrix elements are:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
