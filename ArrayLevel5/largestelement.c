#include <stdio.h>

int main()
{
    int r, c;
    int A[10][10];
    int i, j;
    int max;

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

    // Assume first element is the largest
    max = A[0][0];

    // Find largest element
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(A[i][j] > max)
            {
                max = A[i][j];
            }
        }
    }

    printf("Largest element in the matrix = %d\n", max);

    return 0;
}
