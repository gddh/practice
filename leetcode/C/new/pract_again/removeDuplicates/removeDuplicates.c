#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i;
    int replace;
    int prev;
    int new_i;

    if (numsSize < 1)
        return 0;
    i = 1;
    prev = nums[0];
    new_i = 1;
    replace = 0;
    while (i < numsSize)
    {
        if (prev != nums[i])
        {
            if (replace)
                nums[new_i] = nums[i];
            new_i = new_i + 1;
            prev = nums[i];
        }
        else
            replace = 1;
        i = i + 1;
    }
    return new_i;
}

int main(int argc, char **argv)
{
    int arr[3] = {1,2,3};
    int size = removeDuplicates(arr, 3);
    printf("size is %d\n", size);
    int i = 0;
    while (i < size)
    {
        printf("%d, ", arr[i]);
        i = i + 1;
    }
    printf("\n");
}
