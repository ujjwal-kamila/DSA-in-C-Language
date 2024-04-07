 //C Program to delet data from Begining in an array

#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int arr[MAX_SIZE];
    int i , size,pos,del_item;
    //input Array size
    printf("Enter size of the array : ");
    scanf("%d",&size);

// Exiting program due to invalid array size
    if (size <= 0 || size > MAX_SIZE)  {
        printf("Invalid Array size ");
        return 1;
    }
    else {
    //For Insertion
        printf("Enter the elements of the array : ");
        //Input elements of array as per input size 
        for (i = 0 ; i < size ; i++){
            
            scanf("%d",&arr[i]);
        }
        //print in the input array
        printf("The input array elements are :  ");
        for ( i = 0 ; i <size ; i++) {
            printf("%d  ",arr[i]);
        }

    // Print the item to be deleted
        del_item = arr[0];
        printf("Deleted item is : %d\n", del_item);

        //For delet data from begining 
        for(i = 0 ; i< size -1 ; i++) {
                arr[i] = arr[i+1];
            }
        size --;

        //Display elements
        printf("The array elements are :  ");
        for ( i = 0 ; i <size ; i++) {
            printf(" %d  ",arr[i]);
        }
    }
    return 0;
}