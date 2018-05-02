#include "stack.h"

int		main(int argc, char **argv)
{
	char *postfix;

	if (argc == 2)
	{
		postfix = infix_postfix(argv[1]);
		printf("%s\n", postfix);
	}
}
