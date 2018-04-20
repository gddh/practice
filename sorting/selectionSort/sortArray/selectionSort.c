#include <stdio.h>

void	swap(int *i1, int *i2)
{
	int tmp;

	tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

void	selectionSort(int *arr, int size)
{
	int i;
	int j;
	int min;
	int min_i;

	i = 0;
	while (i < size)
	{
		min = arr[i];
		j = i;
		min_i = i;
		while (j < size)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_i = j;
			}
			j = j + 1;
		}
		swap(&arr[min_i], &arr[i]);
		i = i + 1;
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

	int arr1[] = {1,2,3,4,5,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
	selectionSort(arr1, n1);
    printf("Sorted array: \n");
    printArray(arr1, n1);

	int arr2[] = {7,6,5,4,3,2,1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	selectionSort(arr2, n2);
    printf("Sorted array: \n");
    printArray(arr2, n2);

	int arr3[] = {};
	int n3 = sizeof(arr3) / sizeof(int);
	selectionSort(arr3, n3);
    printf("Sorted array: \n");
    printArray(arr3, n3);

	return 0;
}
