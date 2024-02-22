#include <stdio.h>
#include <stdbool.h>
//lenear serch without recursion

bool search(int arr[], int element, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[5] = {4, 6, 7, 8, 1};
    int size = sizeof(arr) / sizeof(int);
    int element = 9;

    if (search(arr, element, size))
    {
        printf("element is found");
    }
    else
    {
        printf("element is not found");
    }

    return 0;
}