#include <stdio.h>

int main()
{
    int n, i;
    int marks[10];
    int total = 0;
    float average;

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("Enter marks of %d subjects:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    average = total / (float)n;

    printf("\nTotal Marks = %d\n", total);
    printf("Average Marks = %.2f\n", average);

    // Grade calculation
    if(average >= 90)
        printf("Grade: A\n");
    else if(average >= 75)
        printf("Grade: B\n");
    else if(average >= 60)
        printf("Grade: C\n");
    else if(average >= 50)
        printf("Grade: D\n");
    else
        printf("Grade: Fail\n");

    return 0;
}
