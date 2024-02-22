#include <stdio.h>

int linearSearchRecursive(int arr[], int key, int index, int size)
{

    if (index == size)
    {
        return -1;
    }

    if (arr[index] == key)
    {
        return index;
    }

    return linearSearchRecursive(arr, key, index + 1, size);
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 16;

    int result = linearSearchRecursive(arr, key, 0, size);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", key, result);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
