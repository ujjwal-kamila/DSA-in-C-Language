//C Program to delet data from Begining in an array

#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int arr[MAX_SIZE];
    int i , size,pos;
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

        //For delet data from begining 
        for(i = 0 ; i< size -1 ; i++) {
                arr[i] = arr[i+1];
            }
        size --;

        //Display elements
        printf("The array elements are :  ");
        for ( i = 0 ; i <size ; i++) {
            printf("%d  ",arr[i]);
        }
        
    }
    return 0;
}