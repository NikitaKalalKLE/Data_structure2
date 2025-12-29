#include <stdio.h>

int main()
{
    int n;
    int A[10][10];
    int i, j;
    int diagSum = 0, antiDiagSum = 0;

    printf("Enter order of the matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Calculate diagonal and anti-diagonal sums
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                diagSum += A[i][j];

            if(i + j == n - 1)
                antiDiagSum += A[i][j];
        }
    }

    printf("Sum of main diagonal elements = %d\n", diagSum);
    printf("Sum of anti-diagonal elements = %d\n", antiDiagSum);

    return 0;
}
