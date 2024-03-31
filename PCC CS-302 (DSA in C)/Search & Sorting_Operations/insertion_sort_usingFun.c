#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Shift elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;
    int arr[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n > 50) {
        printf("Invalid size \n");
        return 0;
    }
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using insertionSort function
    insertionSort(arr, n);

    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
