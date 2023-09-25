#include <stdio.h>

int LinearSearch(int arr[], int size, int ele)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == ele)
    {
      return i;
    }
  }
  return -1;
}
int BinarySearch(int arr[], int size, int element)
{

  int right, left, mid;

  left = 0;
  right = size - 1;

  while (left <= right)
  {
    mid = (left + right) / 2;
    if (arr[mid] == element)
    {
      return mid;
    }
    if (arr[mid] < element)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return -1;
}

int Deletion(int arr[], int size, int index)
{

  for (int i = index; i < size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }

  return -1;
}

int main()
{
  // int arr[]={12,45,64,23,43,65,78};
  int arr[] = {3, 6, 8, 12, 34, 56, 78};
  int size = sizeof(arr) / sizeof(int);
  int ele = 12;
  // int result=LinearSearch(arr,size,ele);
  int result = BinarySearch(arr, size, ele);
  printf("The element %d found at index %d ", ele, result);

  return 0;
}