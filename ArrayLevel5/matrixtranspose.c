#include <stdio.h>

int main()
{
    int r, c;
    int A[10][10], T[10][10];
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Transpose logic
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            T[j][i] = A[i][j];
        }
    }

    printf("Transpose of the matrix:\n");
    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}
