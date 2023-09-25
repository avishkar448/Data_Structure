#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void SelectionSort(int *a, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
}

int main()
{
    int a[] = {8, 0, 7, 1, 3};
    int n = (sizeof(a)) / (sizeof(a[0]));
    printf("Before Selection Sort: \n");
    PrintArray(a, n);
    printf("After Selection Sort: \n");
    SelectionSort(a, n);
    PrintArray(a, n);
}