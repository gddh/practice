#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int i;
    int new_i;
    int size;

    if (numsSize < 1)
        return 0;
    i = 0;
    new_i = 0;
    size = 0;
    while (i < numsSize)
    {
        if (nums[i] != val)
        {
            nums[new_i] = nums[i];
            new_i = new_i + 1;
            size = size + 1;
        }
        i = i + 1;
    }
    return size;
}

int main()
{
    int arr[] = {3, 2, 2, 3};
    int size = removeElement(arr, 4, 2);
    printf("%d\n", size);
}
