#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare variables
    int i, j;
    
    // Initialize two arrays
    int arr1[4] = {1, 2, 3, 5};
    int arr2[3] = {4, 8, 9};

    // Declare an array to store the merged result
    int arr3[4 + 3];

    // Initialize loop counters
    i = j = 0;

    int in;

    // Merge the two sorted arrays into arr3
    for (in = 0; in < 3 + 4; in++)
    {
        if (i < 4 && j < 3)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[in] = arr1[i];
                i++;
            }
            else
            {
                arr3[in] = arr2[j];
                j++;
            }
        }
        else if (i < 4)
        {
            arr3[in] = arr1[i];
            i++;
        }
        else
        {
            arr3[in] = arr2[j];
            j++;
        }
    }

    // Print the merged array
    printf("The merged array is: \n");
    for (in = 0; in < 4 + 3; in++)
        printf("%d ", arr3[in]);
    printf("\n");

    // Return 0 to indicate successful execution
    return 0;
}
