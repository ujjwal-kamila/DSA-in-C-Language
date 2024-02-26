#include <stdio.h>
int search(int arr[], int N, int x)
{
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
int main(void)
{
	int x, c, n;
	printf("Enter number of elements in array: \n");
	scanf("%d", &n);
	int array[n];
	printf("Enter %d elements: \n", n);
	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);
	printf("Enter a number to search: ");
	scanf("%d", &x);
	int N = sizeof(array) / sizeof(array[0]);
	int result = search(array, N, x);
	(result == -1)
		? printf("Element is not present in array\n")
		: printf("Element is present at index %d\n", result);
	return 0;
}