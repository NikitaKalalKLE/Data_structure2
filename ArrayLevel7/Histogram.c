#include <stdio.h>

int main()
{
    int n, i;
    int marks[50];
    int freq[11] = {0};   // 0–9, 10–19, ..., 90–100

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks (0–100):\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);

        if(marks[i] == 100)
            freq[10]++;
        else
            freq[marks[i] / 10]++;
    }

    printf("\nHistogram (Marks Distribution):\n");
    printf("Range\tFrequency\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d–%d\t%d\n", i*10, i*10 + 9, freq[i]);
    }
    printf("100\t%d\n", freq[10]);

    return 0;
}
