#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int Maximum(int a[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void CountSort(int *a, int n)
{
    int i, j;
    int max = Maximum(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    // Intialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    // Increment the corresponding Index
    for (int i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0; // counter of count array
    j = 0; // counter of main array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {3, 1, 9, 7, 1, 2, 4};
    int n = (sizeof(a)) / (sizeof(a[0]));

    printf("Before Count Sort: \n");
    PrintArray(a, n);
    printf("after Count Sort: \n");
    CountSort(a, n);
    PrintArray(a, n);
}