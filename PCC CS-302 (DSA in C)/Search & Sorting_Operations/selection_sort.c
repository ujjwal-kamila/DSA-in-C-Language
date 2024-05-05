#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_index, temp;
    // Iterate through the array
    for (i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Sorting the array using selectionSort function
    selectionSort(arr, n);
    //printing the sorted lists
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
