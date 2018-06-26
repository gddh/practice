/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target) 
{
    int i;
    int j;
    int *p;
    
    i = 0;
    p = (int *)malloc(sizeof(int) * 2);
    if (p == NULL)
        return (NULL);
    while (i < numsSize)
    {
        j = i + 1;
        while (j < numsSize)
        {
            if (target - nums[i] == nums[j])
            {
                p[0] = i;
                p[1] = j;
                return (p);
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return (p);
}

int main(int argc, char **argv)
{
    int p[3] = {3, 2, 4};
    int *sol;
    sol = twoSum(p, 3, 6);
    printf("%d %d\n", sol[0], sol[1]);
}
