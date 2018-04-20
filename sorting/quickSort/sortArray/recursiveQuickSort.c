#include "stdio.h"

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;

	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int arr[], int low, int high)
{
	int pivot_i;
	int lower_ptr;

	pivot_i = high;
	lower_ptr = low;
	while(low < high)
	{
		if (arr[low] < arr[pivot_i])
			swap(&arr[lower_ptr++], &arr[low]);
		low = low + 1;
	}
	swap(&arr[lower_ptr], &arr[pivot_i]);
	return lower_ptr;
}

void	quickSort(int arr[], int low, int high)
{
	int pivot;

	if (high > low)
	{
		pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void	sort(int arr[], int size)
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
	check(arr, n);
	check(arr1, n1);
	check(arr2, n2);
	check(arr3, n3);
	return 0;
}
