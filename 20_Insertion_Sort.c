#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void InsertionSort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {10, 34, 2, 43, 23};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before Insertion Sort: \n");
    PrintArray(a, n);
    printf("After Insertion sort: \n");
    InsertionSort(a, n);
    PrintArray(a, n);
}