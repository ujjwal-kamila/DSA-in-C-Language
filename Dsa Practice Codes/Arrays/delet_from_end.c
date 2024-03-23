 //C Program to delet data from the  End of an array

#include <stdio.h>
#define MAX_SIZE 50

int main () {
    int arr[MAX_SIZE];
    int i , size , del_item ;

    //Input Array size
    printf("Enter The Size of Array : ");
    scanf("%d",&size);

    //Exiting program due to invalid array size 

    if (size <= 0 || size >MAX_SIZE ) {
        printf("Invalid Array Size ");
        return 1;
    }

    else {

        //For insertion of Array
        printf("Enter the elements of the Array : ");
        for(i=0 ; i<size ; i++){
                scanf("%d",&arr[i]);
        }
        //printing the insertion array
        printf("The input array elements are :  ");
        for ( i = 0 ; i <size ; i++) {
            printf("%d  ",arr[i]);
        }

        //Display the item to be deleted 
        del_item = arr[size-1];
        printf("Deleted Data item is :  %d\n",del_item);

        //for deleting data from the end of array
        size--;

        //Printing the array after deletion
        printf("Updated array elements are : ");

        for (i = 0 ; i <size ; i++){
            printf(" %d  ",arr[i]);
        }
    }
    return 0;
}