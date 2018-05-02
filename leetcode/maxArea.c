#include <stdio.h>

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		maxArea(int *height, int heightSize)
{
	int i;
	int max_area;
	int cur_height;
	int max_width;

	i = 0;
	max_area = 0;

	while (i < heightSize)
	{
		cur_height = min(height[i], height[heightSize - 1]);
		cur_width = heightSize - i - 1;
		if (cur_height * cur_width > max_area)
			max_area = cur_height * cur_width;
		if (height[i] < height[heightSize - 1])
			i++;
		else
			heightSize--;
	}
	return(max_area);
}
