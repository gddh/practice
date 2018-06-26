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

int  size1even(int *p, int size, int v)
{
    return ((size % 2 == 0 && v > p[(size / 2) - 1] && v < p[size / 2]));
}

int size1odd(int *p, int size, int v)
{
    printf("size/2 -1 %d and size/2 + 1 %d\n", p[(size / 2) - 1], p[(size / 2) + 1]);
    return (size % 2 == 1 && v > p[(size / 2) - 1] && v < p[(size / 2) + 1]);
}

int size2cond(int *p1, int *p2, int size1, int size2)
{
    if (size2 == 2 && size1 % 2 == 0 && p1[(size1 / 2) - 1] < p2[0] && p2[1] < p1[(size1 / 2)])
        return 1;
    if (size1 == 2 && size2 % 2 == 0 && p2[(size2 / 2) - 1] < p1[0] && p1[1] < p2[(size2 / 2)])
        return 2;
    return 0;
}

double  findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int offset;
    int med1_is_less;
    //printf("median num1 %f and median num2 %f\n", median(nums1, nums1Size), median(nums2, nums2Size));

    med1_is_less = (median(nums1, nums1Size) < median(nums2, nums2Size));
    if (nums1Size <= 0 && nums2Size <= 0)
        return (0);
    else if (nums1Size <= 0)
        return median(nums2, nums2Size);
    else if (nums2Size <= 0)
        return median(nums1, nums1Size);
    else if (nums1Size + nums2Size == 2)
        return ((float)(nums1[0] + nums2[0]) / 2);
    else if (nums1Size == 1 && size1even(nums2, nums2Size, nums1[0]))
        return nums1[0];
    else if (nums2Size == 1 && size1even(nums1, nums1Size, nums2[0]))
        return nums2[0];
    else if (nums1Size == 1 && size1odd(nums2, nums2Size, nums1[0]))
        return (float)(nums1[0] + nums2[nums2Size / 2]) / 2;
    else if (nums2Size == 1 && size1odd(nums1, nums1Size, nums2[0]))
        return (float)(nums2[0] + nums1[nums1Size / 2]) / 2;
    else if (size2cond(nums1, nums2, nums1Size, nums2Size) == 1)
        return median(nums2, nums2Size);
    else if (size2cond(nums1, nums2, nums1Size, nums2Size) == 2)
        return median(nums1, nums1Size);
    if (med1_is_less)
    {
        offset = nums1Size / 2 - 1;
        if (offset > nums2Size / 2)
            offset = nums2Size / 2;
        if (nums1Size % 2 == 0 || nums2Size % 2 == 0)
            offset = offset - 1;
        if (offset <= 0)
            offset = 1; 
        nums1 = nums1 + offset;
    }
    else
    {
        offset = nums2Size / 2 - 1;
        if (offset > nums1Size / 2)
            offset = nums1Size / 2;
        if (nums1Size % 2 == 0 || nums2Size % 2 == 0)
            offset = offset - 1;
        if (offset <= 0)
            offset = 1;
        nums2 = nums2 + offset;
    }
    return findMedianSortedArrays(nums1, nums1Size - offset, nums2, nums2Size - offset);
}
