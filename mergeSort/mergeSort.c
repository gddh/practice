#include <stdio.h>

int     *mergeSort(int *arr, int len)
{
    if (len <= 1)
        return arr;
    else
        return merge(mergeSort(arr, len / 2), mergeSort(arr + len / 2, len / 2));
}

void    merge(int *arr, int l, int m, int r)
{
    int tmp1[m  - l];
    int tmp2[r - m + 1];
    int i;
    int start = l;

    i = 0;
    while (l < m)
        tmp1[i++] = arr1[l++];
    i = 0;
    while (m < r)
        tmp2[i++] = arr2[m++];

    while(start <= r)
    {
        
        start = start + 1;
    }

}
