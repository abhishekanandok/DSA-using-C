#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return true; 
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return false; 
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 16;

    if (binarySearch(arr, size, key)) {
        printf("Element is found\n");
    } else {
        printf("Element is not found\n");
    }

    return 0;
}
