//Array 
#include <stdio.h>

int main () {
    int arr[50],size, i ;
    printf("Enter size of Array : ");
    scanf("%d",&size);
    printf("Enter the elements of the Arrray : ");
    for (i = 0 ; i < size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the elements are : ");
    for(i = 0 ; i < size ; i++)
    {
        printf("%d  ",arr[i]);
    }
}