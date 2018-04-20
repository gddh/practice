
#include "stack.h"

t_stack		*init_stack(int maxSize)
{
	int		*arr;
	t_stack	*tmp;
	
	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp)
	{
		arr = (int *)malloc(sizeof(int) * maxSize);
		if (!arr)
		{
			fprintf(stderr, "Insufficient memory to intialize array for stack.\n");
			exit(1);
		}
		tmp->ptr = arr;
		tmp->top = -1;
		tmp->maxSize = maxSize;
	}
	return (tmp);
}

void	cpy_arr(int *dst, int *src, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dst[i] = src[i];
		i = i + 1;
	}
}

void	stack_destroy(t_stack *stack)
{
	printf("destroying stack\n");
	free(stack->ptr);
	printf("destroyed array\n");
	free(stack);
	printf("destroyed stack\n");
}

void	resize_stack(t_stack *stack)
{
	int i;
	int *new_arr;

	i = 0;
	if (stack->maxSize <= 0)
		stack->maxSize = 1;
	new_arr = (int *)malloc(sizeof(int) * (stack->maxSize * 2));
	if (!new_arr)
	{
		fprintf(stderr, "Insufficient memory to resize array.\n");
		exit(1);
	}
	cpy_arr(new_arr, stack->ptr, stack->maxSize);
	printf("resizing and freeing\n");
	free(stack->ptr);
	printf("freed original arr\n");
	stack->ptr = new_arr;
	stack->maxSize = stack->maxSize * 2;
}

int		is_full(t_stack *stack){
	return (stack->top >= stack->maxSize - 1);
}

int		is_empty(t_stack *stack)
{
	return stack->top == -1;
}

void	stack_push(t_stack *stack, int data)
{
	if (is_full(stack))
		resize_stack(stack);
	stack->ptr[++stack->top] = data;
}

int		stack_pop(t_stack *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Cannot pop from empty stack. \n");
		exit(1);
	}
	return (stack->ptr[stack->top--]);
}
