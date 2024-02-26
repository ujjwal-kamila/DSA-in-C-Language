#include <stdio.h>
#define max_size 50
// Function to insert an element into the array at a specified position
int insertElement(int arr[], int size, int element, int position) {
    // Check if the array is full
    if (size == max_size) {
        printf("Array is full. Cannot insert more elements.\n");
        return size;
    }
    // Check if the position is valid
    if (position < 0 || position > size) {
        printf("Invalid position. Position should be between 0 and %d (inclusive).\n", size);
        return size;
    }
    // Shift elements to make space for the new element
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    // Insert the new element at the specified position
    arr[position] = element;
    return size + 1;
}
// Function to delete an element from the array at a specified position
int deleteElement(int arr[], int size, int position) {
    // Check if the array is empty
    if (size == 0) {
        printf("Array is empty. Cannot delete an element.\n");
        return size;
    }
    // Check if the position is valid
    if (position < 0 || position >= size) {
        printf("Invalid position. Position should be between 0 and %d (inclusive).\n", size - 1);
        return size;
    }
    // Shift elements to remove the element at the specified position
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}
// Function to display the elements of the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
// Main function
void main() {
    // Initialize an array with some elements
    int arr[20] = {1, 2, 3, 4, 5};

    // Display the original array
    displayArray(arr, 5);

    // Insert an element at position 1
    insertElement(arr, 5, 10, 1);

    // Display the array after insertion
    displayArray(arr, 6);

    // Delete an element at position 2
    deleteElement(arr, 6, 2);

    // Display the array after deletion
    displayArray(arr, 5);
}
