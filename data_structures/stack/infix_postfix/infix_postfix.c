#include "stack.h"

int		priority(char c)
{
	if (c == '^')
		return (3);
	if (c == '*' || c == '/' || c == '%')
		return (2);
	if (c == '+' || c == '-')
		return (1);
	if (c == '(')
		return (0);
	return (4);
}

void	process(char *str, t_stack **stack, char *res, int *res_i, int *i)
{
	char tmp;

	if (str[*i] == '(')
	{
		push(stack, str[*i]);
	}
	else if (str[*i] == ')')
	{
		while (!is_empty(*stack) && peek(*stack) != '(')
		{
			tmp = pop(stack); 
			res[(*res_i)++] = tmp;
			res[(*res_i)++] = ' ';
		}
		pop(stack);
	}
	else if ((str[*i] >= '0' && str[*i]  <= '9'))
	{
		res[(*res_i)++] = str[*i];
		if (str[*i + 1] == ' ' || str[*i + 1] == '\0')
			res[(*res_i)++] = ' ';

	}
	else if (!is_empty(*stack) && priority(str[*i]) <= priority(peek(*stack)))
	{
		while (!is_empty(*stack) && priority(str[*i]) <= priority(peek(*stack)))
		{
			tmp = pop(stack);
			res[(*res_i)++] = tmp;
			res[(*res_i)++] = ' ';
		}
		push(stack, str[*i]);
	}
	else if (priority(str[*i]) < 4)
	{
		push(stack, str[*i]);
	}
}


char	*infix_postfix(char *str)
{
	char	*res;
	t_stack	*stack;
	int		res_i;
	size_t	size;
	int		i;

	size = num_ops(str) * 2;
	res = (char *)malloc(sizeof(char) * size);
	check_malloc(res);
	stack = init_stack();
	i = 0;
	res_i = 0;
	while (str[i] != '\0')
	{
		process(str, &stack, res, &res_i, &i);
		i++;
	}
	while(!is_empty(stack))
	{
		res[res_i++] = pop(&stack);
		res[res_i++] = ' ';
	}
	res[res_i - 1] = '\0';
	return (res);
}
