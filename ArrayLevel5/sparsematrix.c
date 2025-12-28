#include <stdio.h>

int main()
{
    int r, c;
    int A[10][10];
    int sparse[20][3];
    int i, j, k = 1;

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

    // First row stores matrix info
    sparse[0][0] = r;
    sparse[0][1] = c;

    // Convert to sparse form
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(A[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = A[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;

    printf("\nSparse Matrix Representation:\n");
    printf("Row Col Value\n");
    for(i = 0; i < k; i++)
    {
        printf("%d   %d   %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}
