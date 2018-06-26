#include <stdlib.h>

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return i;
}

int     check_palindrome(char *str, int i, int j)
{
    while (i < j && str[i] == str[j])
    {
        i = i + 1;
        j = j - 1;
    }
    if (str[i] == str[j])
        return (1);
    return (0);
}

char    *create_substr(char *str, int i, int j)
{
    char *tmp;
    int ti;

    tmp = (char *)malloc(sizeof(char) * (j - i + 2));
    if(tmp)
    {
        ti = 0;
        while (i + ti <= j)
        {
            tmp[ti] = str[i + ti];
            ti = ti + 1;
        }
        tmp[ti] = '\0';
        return tmp;
    }
    return NULL;
}

char    *longestPalindrome(char *str)
{
    int i;
    int end;
    int j;
    int x;

    j = ft_strlen(str) - 1;
    end = j;
    while (j > 0)
    {
        x = j;
        i = 0;
        while (x <= end)
        {
            if (check_palindrome(str, i, x) == 1)
                return create_substr(str, i, x);
            i = i + 1;
            x = x + 1;
        }
        j = j - 1;
    }
    return NULL;
}
