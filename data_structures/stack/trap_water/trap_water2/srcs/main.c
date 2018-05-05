#include <trap.h>

int		main(void)
{
	int arr[] = {9,5,7,8,7,2,0,9,4,9,6,6,7,6,6,3,4,9,5};
	printf("%d\n", trap(arr, sizeof(arr)/sizeof(arr[0])));
	leaks();
}
