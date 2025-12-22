#include <stdio.h>

int main()
{
    int r, c;
    int A[10][10], B[10][10], C[10][10];
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Addition
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Resultant Matrix (A + B):\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
