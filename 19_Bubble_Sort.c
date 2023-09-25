#include <stdio.h>

void PrintArray(int *a, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void BubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for the number of passes
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {12, 54, 21, 11, 90, 32};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Elements before sorting:\n ");
    PrintArray(a, n);
    printf("Elements after sorting:\n ");
    BubbleSort(a, n);
    PrintArray(a, n);
}