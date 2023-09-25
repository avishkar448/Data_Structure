#include <stdio.h>

void display(int arr[], int num)
{

    for (int i = 0; i < num; i++)
    {
        printf("%d", arr[i]);
        printf("\t");
    }
}

int Insertion_array(int arr[], int n, int ele, int size, int index)
{

    if (size >= n)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index - 1] = ele;

        return 1;
    }
}

int main()
{
    int arr[50] = {43, 54, 67, 98, 23};
    int n;
    int size = 5;
    int index;

    Insertion_array(arr, 50, 100, 5, 3);
    size++;
    display(arr, size);

    return 0;
}