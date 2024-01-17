#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix element
struct SparseMatrix
{
    int row;
    int col;
    int value;
};

// Function to add two sparse matrices and print the result
void addSparseMatrices(struct SparseMatrix matrix1[], struct SparseMatrix matrix2[], int size1, int size2)
{
    // Initialize variables
    int maxSize = size1 + size2;
    struct SparseMatrix result[maxSize];
    int i = 0, j = 0, k = 0;

    // Merge matrices while considering row and column indices
    while (i < size1 && j < size2)
    {
        if (matrix1[i].row < matrix2[j].row ||
            (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col))
        {
            result[k++] = matrix1[i++];
        }
        else if (matrix1[i].row > matrix2[j].row ||
                 (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col))
        {
            result[k++] = matrix2[j++];
        }
        else
        {
            // Add values when row and column indices match
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            k++;
            i++;
            j++;
        }
    }

    // Copy remaining elements from matrix1, if any
    while (i < size1)
    {
        result[k++] = matrix1[i++];
    }

    // Copy remaining elements from matrix2, if any
    while (j < size2)
    {
        result[k++] = matrix2[j++];
    }

    // Print the resulting sparse matrix
    printf("Resulting Sparse Matrix:\n");
    for (int l = 0; l < k; l++)
    {
        printf("(%d, %d, %d)\n", result[l].row, result[l].col, result[l].value);
    }
}

int main()
{
    // Declare variables
    int size1, size2;

    // Input size and elements of the first sparse matrix
    printf("Enter the size of the first sparse matrix: ");
    scanf("%d", &size1);
    struct SparseMatrix matrix1[size1];
    printf("Enter the elements of the first sparse matrix (row col value):\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    // Input size and elements of the second sparse matrix
    printf("Enter the size of the second sparse matrix: ");
    scanf("%d", &size2);
    struct SparseMatrix matrix2[size2];
    printf("Enter the elements of the second sparse matrix (row col value):\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    // Call the function to add sparse matrices and print the result
    addSparseMatrices(matrix1, matrix2, size1, size2);

    return 0;
}
