#include "stdio.h"

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;

	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	swap(int *i1, int *i2)
{
	int tmp;

	tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

int		partition(int *arr, int l, int r)
{
	int p_i;
	int ptr;

	p_i = r;
	ptr = l;
	while(l < r)
	{
		if (arr[l] < arr[p_i])
			swap(&arr[ptr++], &arr[l]);
		l = l + 1;
	}
	swap(&arr[ptr], &arr[p_i]);

	return ptr;
}

void	quickSort(int *arr, int l, int r)
{
	int p_i;

	while (l < r)
	{
		p_i = partition(arr, l, r);

		if (p_i - l < r - p_i)
		{
			quickSort(arr, l, p_i - 1);
			l = p_i + 1;
		}
		else
		{
			quickSort(arr, p_i + 1, r);
			r = p_i - 1;
		}
	}
}

void	sort(int *arr, int size)
{
	quickSort(arr, 0, size - 1);
}

void	check(int *arr, int n)
{
	printf("Original array: ");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("Sorted   array: ");
	printArray(arr, n);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int arr1[] = {1,2,3,4,5,6,7};
	int n1 = 7;
	int arr2[] = {7,6,5,4,3,2,1};
	int n2 = 7;
	int arr3[] = {};
	int n3 = 0;
	int arr4[] = {2,1, 3};
	int n4 = 3;
	check(arr4, n4);
	check(arr, n);
	check(arr1, n1);
	check(arr2, n2);
	check(arr3, n3);
	return 0;
}
