// Array insertion in C 
#include <stdio.h>
#define MAX_SIZE 50

void main() {
    int arr[MAX_SIZE], size, i;
    
    // Tell user to enter the size of the array
    printf("Enter the size of Array: ");
    scanf("%d", &size);
    
    // Checking if the entered size is valid
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid Array size :(\n");
    }
    else {
        // Input elements of array as per input size
        printf("Enter the elements of the Array: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Displaying the elements of the array
        printf("The Array Elements are: ");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    }
}
