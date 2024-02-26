#include <stdio.h>

#define max_size 50

// Function to insert an element at a specified position in the array
int insertElement(int arr[], int *size, int element, int position) {
    // Check if the array is full
    if (*size == max_size) {
        printf("Array is full. Cannot insert more elements.\n");
        return 0;  // Indicate failure
    }

    // Check if the position is valid
    if (position < 0 || position > *size) {
        printf("Invalid position. Position should be between 0 and %d (inclusive).\n", *size);
        return 0;  // Indicate failure
    }

    // Shift elements to make space for the new element
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the specified position
    arr[position] = element;

    // Increment the size of the array
    (*size)++;

    return 1;  // Indicate success
}

// Function to delete an element from a specified position in the array
int deleteElement(int arr[], int *size, int position) {
    // Check if the array is empty
    if (*size == 0) {
        printf("Array is empty. Cannot delete an element.\n");
        return 0;  // Indicate failure
    }

    // Check if the position is valid
    if (position < 0 || position >= *size) {
        printf("Invalid position. Position should be between 0 and %d (exclusive).\n", *size);
        return 0;  // Indicate failure
    }

    // Shift elements to remove the element at the specified position
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array
    (*size)--;

    return 1;  // Indicate success
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

int main() {
    int arr[max_size];
    int size = 0;

    // Input array size from the user
    printf("Enter the size of the array (max %d): ", max_size);
    scanf("%d", &size);

    if (size > max_size || size < 0) {
        printf("Invalid array size.\n");
        return 1;  // Exit with an error code
    }

    // Input array elements from the user
    printf("Enter %d elements for the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    displayArray(arr, size);

    // Insert an element at a specified position
    int insertPosition, insertElementValue;
    printf("Enter the position to insert: ");
    scanf("%d", &insertPosition);
    printf("Enter the element to insert: ");
    scanf("%d", &insertElementValue);

    if (insertElement(arr, &size, insertElementValue, insertPosition)) {
        printf("Element inserted successfully.\n");
        displayArray(arr, size);
    } else {
        printf("Failed to insert element.\n");
    }

    // Delete an element from a specified position
    int deletePosition;
    printf("Enter the position to delete: ");
    scanf("%d", &deletePosition);

    if (deleteElement(arr, &size, deletePosition)) {
        printf("Element deleted successfully.\n");
        displayArray(arr, size);
    } else {
        printf("Failed to delete element.\n");
    }

    return 0;  // Exit successfully
}