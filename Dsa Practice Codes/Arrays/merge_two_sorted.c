#include<stdio.h>

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
    int i = 0, j = 0, k = 0; // Initialize indices for arr1, arr2, and arr3 respectively

    // Traverse arr1 and arr2 to merge elements into arr3
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) { // If element in arr1 is smaller
            arr3[k++] = arr1[i++]; // Copy it to arr3 and move to next element in arr1
        } else { // If element in arr2 is smaller or equal
            arr3[k++] = arr2[j++]; // Copy it to arr3 and move to next element in arr2
        }
    }

    // Copy remaining elements from arr1, if any
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

// Function to take user input for an array
void inputArray(int arr[], int size) {
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Driver code
int main() {
    int arr1[50], arr2[50], arr3[100]; // Maximum size set to 50 for each array
    int n1, n2; // Sizes of arr1 and arr2

    // Input size and elements for arr1
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    inputArray(arr1, n1);

    // Input size and elements for arr2
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    inputArray(arr2, n2);

    // Merge arrays arr1 and arr2 into arr3
    mergeArrays(arr1, arr2, n1, n2, arr3);

    // Print the merged array
    printf("Array after merging:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
