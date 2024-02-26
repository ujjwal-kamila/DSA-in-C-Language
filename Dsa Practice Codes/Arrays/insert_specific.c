//C Program to insert Elements at specifice poisition in an array

#include <stdio.h>
#define MAX_SIZE 50

int main () {
    int arr[MAX_SIZE];
    int i , size , num , pos;
    printf("Enter the size of the array : ",MAX_SIZE);
    scanf("%d",&size);
    
    // Exiting program due to invalid array size
    if(size<= 0 || size > MAX_SIZE)
    {
        printf("Overflow :)");
        return 1;
    }

    else 
    {
        printf("Enter elemetns of the array : ");
        for (i = 0 ; i < size ; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Array Elemetns are : ");
        for(i = 0 ; i<size ; i++)
        {
            printf("%d ",arr[i]);
        }

    //For Insertion 
        printf("Enter data to insert : " );
        scanf("%d",&num);

        printf("Enter Poisition  to insert : ", size+1 );
        scanf("%d",&pos);

    //Check for invalid position
        if (pos < 1 || pos > size + 1)
        {
            printf("Invalid Position ");
        }

    // Shift elements to make space for the new element
        for (i = size -1; i > pos-1 ; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[pos -1] = num ;
        size ++;

    //Display elements
        printf("The array Elements are : ");
        for(i=0 ; i<size ; i++)
        {
            printf("%d  ",arr[i]);
        }
    }
    return 0;
}