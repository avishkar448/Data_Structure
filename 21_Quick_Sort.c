#include <stdio.h>

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void QuickSort(int a[], int low, int high)
{
    int partitionIndex; // Index of Pivot after sorting
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        QuickSort(a, low, partitionIndex - 1);
        QuickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {21, 3, 44, 56, 7, 11, 66};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Array before Quick Sort: \n");
    PrintArray(a, n);
    printf("Array after Quick Sort: \n");
    QuickSort(a, 0, n - 1);
    PrintArray(a, n);
}