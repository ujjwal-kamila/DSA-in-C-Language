 //C Program to insert delet display elements by positon in an array 
#include<stdio.h>

#define MAX_SIZE 50

int main() {
    int arr[MAX_SIZE];
    int i, size, num, pos, del_item;

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

        // Insertion at specific position
        printf("\nEnter position to insert: ");
        scanf("%d", &pos);

        if (pos < 0 || pos > size + 1) {
            printf("Invalid position");
        }
        else {
            printf("Enter data to insert: ");
            scanf("%d", &num);
            for (i = size - 1; i >= pos - 1; i--) {
                arr[i + 1] = arr[i];
            }
            arr[pos - 1] = num;
            size++;
        }

        // Display Array elements after insertion
        printf("\nThe array elements after insertion are: ");
        for (i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
        }

        // Deletion at specific position
        printf("\nEnter position to delete: ");
        scanf("%d", &pos);

        if (pos <= 0 || pos > size) {
            printf("Invalid position");
        }
        else {
            del_item = arr[pos - 1];
            for (i = pos - 1; i < size - 1; i++) {
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
