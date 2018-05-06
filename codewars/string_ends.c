#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool	solution(const char *string, const char *ending)
{
	int string_i;
	int ending_i;
	int i;

	string_i = strlen(string) - 1;
	ending_i = strlen(ending) - 1;
	i = 0;
	while (i <= ending_i)
	{
		if (string[string_i + i] != ending[ending_i + i])
			return (0);
		i = i + 1;
	}
	return (1);
}

int		main(void)
{
	printf("%d\n", solution("abc", "d"));
}
