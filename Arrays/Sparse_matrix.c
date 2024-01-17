#include <stdio.h>
#include <stdlib.h>
struct SparseMatrix
{
    int row;
    int col;
    int value;
};
void addSparseMatrices(struct SparseMatrix matrix1[], struct SparseMatrix matrix2[], int size1, int size2)
{
    int maxSize = size1 + size2;
    struct SparseMatrix result[maxSize];
    int i = 0, j = 0, k = 0;
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
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            k++;
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        result[k++] = matrix1[i++];
    }
    while (j < size2)
    {
        result[k++] = matrix2[j++];
    }
    printf("Resulting Sparse Matrix:\n");
    for (int l = 0; l < k; l++)
    {
        printf("(%d, %d, %d)\n", result[l].row, result[l].col, result[l].value);
    }
}
int main()
{
    int size1, size2;
    printf("Enter the size of the first sparse matrix: ");
    scanf("%d", &size1);
    struct SparseMatrix matrix1[size1];
    printf("Enter the elements of the first sparse matrix (row col value):\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }
    printf("Enter the size of the second sparse matrix: ");
    scanf("%d", &size2);
    struct SparseMatrix matrix2[size2];
    printf("Enter the elements of the second sparse matrix (row col value):\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }
    addSparseMatrices(matrix1, matrix2, size1, size2);
    return 0;
}