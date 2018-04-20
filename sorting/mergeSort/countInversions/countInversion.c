#include <stdlib.h>
#include <stdio.h>

void	fill_tmp(int *dst, int *src, int start, int n)
{
	int i;

	i = 0;
	while (i < n)
		dst[i++] = src[start++];
}

int		merge_sorted(int *dst, int *src1, int *src2, int n1, int n2)
{
	int i1;
	int i2;
	int count;

	i1 = 0;
	i2 = 0;
	count = 0;
	while (i1 < n1 && i2 < n2)
	{
		if (src1[i1] < src2[i2])
			*dst++ = src1[i1++];
		else
		{
			count = count + (n1 - i1);
			*dst++ = src2[i2++];
		}
	}
	while (i1 < n1)
		*dst++ = src1[i1++];
	while (i2 < n2)
		*dst++ = src2[i2++];
	return (count);
}

int		merge_count(int *arr, int l, int m, int r)
{
	int size1 = m - l + 1;
	int size2 = r - m;
	int t1[size1];
	int t2[size2];

	fill_tmp(t1, arr, l, size1);
	fill_tmp(t2, arr, m + 1, size2);
	return (merge_sorted(arr + l, t1, t2, size1, size2));
}

int		mergeSort(int *arr, int l, int r)
{
	int count;

	if (r <= l)
		return (0);
	else
	{
		count = 0;
		count = mergeSort(arr, l, (l + r) / 2);
		count = mergeSort(arr, ((l + r) / 2) + 1, r) + count;
		return merge_count(arr, l, (l + r) / 2, r) + count;
	}
}

int		inversionCount(int *arr, int arr_size)
{
	return mergeSort(arr, 0, arr_size - 1);
}


int main(int argv, char** args)
{
	int arr[] = {2,4,1,3,5};
	printf(" Number of inversions are %d \n", inversionCount(arr, 5));
	int arr1[] = {1,2,3,4,5};
	printf(" Number of inversions are %d \n", inversionCount(arr1, 5));
	int arr2[] = {1, 5, 4, 8, 10, 2, 6, 9, 3, 7};
	printf(" Number of inversions are %d \n", inversionCount(arr2, 10));
	int arr3[] ={};
	printf(" Number of inversions are %d \n", inversionCount(arr2, 0));
	return 0;
}
