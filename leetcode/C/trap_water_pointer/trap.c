#include <stdio.h>

int	trap(int *height, int heightSize)
{
	int left_ptr;
	int max_left;
	int max_right;
	int right_ptr;
	int total;

	left_ptr = 0;
	right_ptr = heightSize - 1;
	max_left = height[left_ptr];
	max_right = height[right_ptr];
	total = 0;
	while (left_ptr < right_ptr)
	{
		if (max_left < max_right)
		{
			left_ptr = left_ptr + 1;
			if (height[left_ptr] < max_left)
				total = total + max_left - height[left_ptr];
			else
				max_left = height[left_ptr];
		}
		else
		{
			right_ptr = right_ptr - 1;
			if (height[right_ptr] < max_right)
				total = total + max_right - height[right_ptr];
			else
				max_right = height[right_ptr];
		}
	}
	return (total);
}

int		main(void)
{
	int heights[] = {5,5,1,7,1,1,5,2,7,6};
	printf("%d\n", trap(heights, sizeof(heights)/sizeof(heights[0])));
}
