#include <stdio.h>
#include <stdlib.h>

int		binary_search(int arr[], int l, int r, int x)
{
	if (l > r)
		return (-1);
	if (arr[(l + r) / 2] == x)
		return (l + r) / 2;
	if (arr[(l + r) / 2] < x)
		return binary_search(arr, ((l + r) / 2) + 1, r, x);
	if (arr[(l + r) / 2] > x)
		return binary_search(arr, l, ((l + r) / 2) - 1, x);
	return (-1);
}

int		*range_arr(int prev_lower, int prev_upper)
{
	int *range;

	range = (int *)malloc(sizeof(int) * 2);
	if (!range)
	{
		fprintf(stderr, "Insufficient space for malloc.\n");
		exit(1);
	}
	range[0] = prev_lower;
	range[1] = prev_upper;
	return (range);
}

int		*searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int lower_bound;
	int prev_lower;
	int upper_bound;
	int prev_upper;

	lower_bound = binary_search(nums, 0, numsSize - 1, target);
	upper_bound = binary_search(nums, 0, numsSize - 1, target);
	prev_lower = lower_bound;
	prev_upper = upper_bound;
	while (lower_bound != -1)
	{
		prev_lower = lower_bound;
		lower_bound = binary_search(nums, 0, lower_bound - 1, target);
	}
	while (upper_bound != -1)
	{
		prev_upper = upper_bound;
		upper_bound = binary_search(nums, upper_bound + 1, numsSize - 1, target);
	}
	returnSize = range_arr(prev_lower, prev_upper);
	return (returnSize);
}


int main(void)
{
   int arr[] = {5, 7, 7, 8, 8, 10};
   int *sol = searchRange(arr, 6, 6, arr);
   printf("%d %d\n", sol[0], sol[1]);
   return 0;
}
