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

void    print_array(int *p, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%d, ", p[i]);
        i = i + 1;
    }
}

void    basic_print(int offset, int *nums1, int v1, int *nums2, int v2)
{
        printf("printing nums1: ");
        print_array(nums1, v1);
        printf("\t nums2: ");
        print_array(nums2, v2);
        printf("\t\toffset %d\n", offset); 
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
    basic_print(offset, nums1, nums1Size - offset, nums2, nums2Size - offset);
    return findMedianSortedArrays(nums1, nums1Size - offset, nums2, nums2Size - offset);
}

int     main(void)
{
    int p_size;
    int p2_size;
    p_size = 4;
    p2_size = 6;
    int p[] = {1, 5,6, 8};
    int p2[] = {2,3, 4, 7, 9, 10};
    basic_print(0, p, p_size, p2, p2_size);
    printf("%f\n", findMedianSortedArrays(p, p_size, p2, p2_size));
}
