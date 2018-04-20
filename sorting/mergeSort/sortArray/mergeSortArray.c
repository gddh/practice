#include <stdio.h>

/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void    merge(int *arr, int l, int m, int r)
{
	int size1 = m - l + 1;
	int size2 = r - m;
    int tmp1[size1];
    int tmp2[size2];
    int i;
	int i1;
	int i2;

    i = 0;
    while (i < size1)
	{
        tmp1[i] = arr[l + i];
		i = i + 1;
	}
    i = 0;
    while (i < size2)
	{
        tmp2[i] = arr[m + i + 1];
		i = i + 1;
	}
	i = 0;
	i1 = 0;
	i2 = 0;
	while (i1 < size1 && i2 < size2)
	{
		if (tmp1[i1] < tmp2[i2])
			arr[l + i] = tmp1[i1++];
		else
			arr[l + i] = tmp2[i2++];
		i = i + 1;
	}
	while (i1 < size1)
	{	
		arr[l + i] = tmp1[i1++];
		i = i + 1;
	}
	while (i2 < size2)
	{	
		arr[l + i] = tmp2[i2++];
		i = i + 1;
	}
}



int     *mergeSort(int *arr, int l, int r)
{
    if (r > l)
	{
		mergeSort(arr, l, (l + r) / 2);
		mergeSort(arr, (l + r) / 2 + 1, r);
        merge(arr, l, (l + r) / 2, r);	
	}
	return arr;
}

 
/* Driver program to test above functions */
int main()
{
    //int arr[] = {12, 11, 13, 5, 6, 7};
	//int arr[] = {1,2,5,2,4,3,7,6,9,8};
	//int arr[] = {1};
	int arr[0];
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
