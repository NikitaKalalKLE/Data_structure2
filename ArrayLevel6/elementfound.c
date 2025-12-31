#include <stdio.h>

int main()
{
    int r, c;
    int A[10][10];
    int i, j;
    int key, found = 0;

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

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Search operation
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(A[i][j] == key)
            {
                printf("Element %d found at position (%d, %d)\n",
                       key, i + 1, j + 1);
                found = 1;
                break;
            }
        }
        if(found == 1)
            break;
    }

    if(found == 0)
        printf("Element %d not found in the matrix.\n", key);

    return 0;
}
