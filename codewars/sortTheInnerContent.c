#include <string.h>
#include <stdio.h>

int		is_whitespace(char c)
{
	return (c == ' ' || (c < 14 && c > 8));
}

int		word_begins(char *words, int i)
{
	if (i == 0)
		return !is_whitespace(words[i]);
	return (is_whitespace(words[i - 1]) && !is_whitespace(words[i]));
}

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !is_whitespace(str[i]))
		i = i + 1;
	return (i);
}

void	sortWord(char *words)
{
	int j;
	int i;
	int min_index;
	int str_len;

	words = words + 1;
	i = 0;
	str_len = word_len(words);
	while (i < str_len - 1)
	{
		j = i;
		min_index = i;
		while (j < str_len - 1)
		{
			if (words[j] > words[min_index])
				min_index = j;
			j = j + 1;
		}
		swap(&words[i], &words[min_index]);
		i = i + 1;
	}
}

char	*sortTheInnerContent(const char	*words, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = strdup(words);
	while (str[i] != '\0' && i < len)
	{
		if (word_begins(str, i))
		{
			sortWord(str + i);
		}
		i = i + 1;
	}
	return str;
}

int		main(void)
{
	char str[] = "this kata is easy";
	printf("%s\n", sortTheInnerContent(str, strlen(str)));
}
