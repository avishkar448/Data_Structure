#include <stdio.h>

void display(int arr[], int num)
{

    for (int i = 0; i < num; i++)
    {
        printf("%d", arr[i]);
        printf("\t");
    }
}

int main()
{
    int a[20], size, index;
    printf("How many number you want to insert:  ");
    scanf("%d", &size);

    printf("Enter the element:  ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Element before deletion:  ");
    display(a, size);

    printf("index number you want to delete: ");
    scanf("%d", &index);

    for (int i = index; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    size--;

    printf("Element after deletion:  ");
    display(a, size);
}