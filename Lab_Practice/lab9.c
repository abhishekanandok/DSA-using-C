#include <stdio.h>
#include <stdbool.h>

//binaray using recursion
bool BinarySearchRecursive(int arr[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return true;
        }

        if (key < arr[mid])
        {
            BinarySearchRecursive(arr, key, low, mid - 1);
        }
        else
        {
            BinarySearchRecursive(arr, key, mid + 1, high);
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 16;

    if (BinarySearchRecursive(arr, key, 0, size - 1))
    {
        printf("element is found");
    }
    else
    {
        printf("element is not found");
    }

    return 0;
}
