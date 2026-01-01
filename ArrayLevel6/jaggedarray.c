#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j;
    int *arr[10];      // array of pointers
    int cols[10];      // stores column size of each row

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Allocate memory for each row
    for(i = 0; i < rows; i++)
    {
        printf("Enter number of columns for row %d: ", i + 1);
        scanf("%d", &cols[i]);

        arr[i] = (int *)malloc(cols[i] * sizeof(int));

        if(arr[i] == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // Read elements
    printf("Enter elements of the jagged array:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols[i]; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display elements
    printf("Jagged array elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(i = 0; i < rows; i++)
    {
        free(arr[i]);
    }

    return 0;
}
