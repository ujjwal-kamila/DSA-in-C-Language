 //C Program to insert delet display elements by index in an array 

#include<stdio.h>

#define MAX_SIZE 50

int main() {
    int arr[MAX_SIZE];
    int i, size, num, index, del_item;

    // Input Array size
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Exiting program due to invalid array size
    if (size <= 0 || size > MAX_SIZE)  {
        printf("Invalid Array size");
        return 1;
    }
    else {
        // For Insertion
        printf("Enter the elements of the array: ");
        // Input elements of array as per input size 
        for (i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        // Printing the inserted array
        printf("The input array elements are: ");
        for (i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
        }

        // Insertion at specific index
        printf("\nEnter index to insert: ");
        scanf("%d", &index);

        if (index < 0 || index > size) {
            printf("Invalid index");
        }
        else {
            printf("Enter data to insert: ");
            scanf("%d", &num);
            for (i = size - 1; i >= index; i--) {
                arr[i + 1] = arr[i];
            }
            arr[index] = num;
            size++;
        }

        // Display Array elements after insertion
        printf("\nThe array elements after insertion are: ");
        for (i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
        }

        // Deletion at specific index
        printf("\nEnter index to delete: ");
        scanf("%d", &index);

        if (index < 0 || index >= size) {
            printf("Invalid index");
        }
        else {
            del_item = arr[index];
            for (i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            printf("The deleted item is: %d ", del_item);
        }

        // Display Array elements after deletion
        printf("\nThe array elements after deletion are: ");
        for (i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
        }
    }
    return 0;
}
