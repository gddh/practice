#include <stdio.h>

double  median(int *p, int size)
{
    int upper;
    int lower;

    if (size % 2 == 1)
        return p[(size - 1) / 2];
    else
    {
        upper = p[size / 2];
        lower = p[(size - 1) / 2];
        return (double)(upper + lower) / 2;
    }
}

double  find_median(double v1, double v2, double v3)
{
    if (v1 <= v2)
    {
        if (v2 <= v3)
            return v2;
        if (v3 <= v1)
            return v1;
    }
    else
    {
        if (v3 <= v2)
            return v2;
        if (v1 <= v3)
            return v1;
    }
    return v3;
}

double  find_double(int *n1, int *n2)
{
    int p[4];
    int i1;
    int i2;

    i1 = 0;
    i2 = 0;
    while (i1 + i2 < 4)
    {
        if (i1 == 2)
        {
            p[i1 + i2] = n2[i2];
            i2 = i2 + 1;
        }
        else if (i2 == 2)
        {
            p[i1 + i2] = n1[i1];
            i1 = i1 + 1;
        }
        else if (n1[i1] <= n2[i2])
        {
            p[i1 + i2] = n1[i1];
            i1 = i1 + 1;
        }
        else if (n2[i2] <= n1[i1])
        {
            p[i1 + i2] = n2[i2];
            i2 = i2 + 1;
        } 
    }
    return (float)(p[1] + p[2]) /2;
}

int  size1cond(int *p, int size, int v)
{
    return ((size % 2 == 0 && v > p[(size / 2) - 1] && v < p[size / 2]));
}

double  findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int offset;
    int med1_is_less;

    med1_is_less = (median(nums1, nums1Size) < median(nums2, nums2Size));
    if (nums1Size <= 0 && nums2Size <= 0)
        return (0);
    else if (nums1Size <= 0)
        return median(nums2, nums2Size);
    else if (nums2Size <= 0)
        return median(nums1, nums1Size);
    else if (nums1Size + nums2Size == 2)
        return ((float)(nums1[0] + nums2[0]) / 2);
    else if (nums1Size == 1 && size1cond(nums2, nums2Size, nums1[0]))
        return nums1[0];
    else if (nums2Size == 1 && size1cond(nums1, nums1Size, nums2[0]))
        return nums2[0];
    if (med1_is_less)
    {
        offset = nums1Size / 2 - 1;
        if (offset <= 0)
            offset = 1;
        if (offset > nums2Size)
            offset = nums2Size;
        nums1 = nums1 + offset;
    }
    else
    {
        offset = nums2Size / 2 - 1;
        if (offset <= 0)
            offset = 1;
        if (offset > nums1Size)
            offset = nums1Size;
        nums2 = nums2 + offset;
    }
    return findMedianSortedArrays(nums1, nums1Size - offset, nums2, nums2Size - offset);
}
