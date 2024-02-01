#include <stdio.h>
void addPolynomials(int poly1[], int poly2[], int result[],
                    int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (poly1[i] >= poly2[j])
        {
            result[k++] = poly1[i++];
        }
        else
        {
            result[k++] = poly2[j++];
        }
    }
    while (i < m)
    {
        result[k++] = poly1[i++];
    }
    while (j < n)
    {
        result[k++] = poly2[j++];
    }
}
void printPolynomial(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%dx^%d%s", poly[i], n - i - 1, (i != n - 1) ? " + " : "\n");
    }
}
int main()
{
    int m, n;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &m);
    int poly1[m];
    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &poly1[i]);
    }
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n);
    int poly2[n];
    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &poly2[i]);
    }
    int maxDegree = (m > n) ? m : n;
    int result[maxDegree];
    addPolynomials(poly1, poly2, result, m, n);
    printf("Sum of the two polynomials:\n");
    printPolynomial(result, maxDegree);
    return 0;
}