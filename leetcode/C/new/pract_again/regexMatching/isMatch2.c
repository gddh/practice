#include <stdio.h>

int     isMatch(char *s, char *p)
{
    int firstMatch;
    printf("s is |%s| p is |%s|\n", s, p);

    if (s[0] == '\0' && p[0] == '\0')
        return 1;
    else if (p[0] != '\0' && p[1] == '*')
    {
        firstMatch = s[0] && (s[0] == p[0] || p[0] == '.');
        return isMatch(s, p + 2) || (firstMatch && isMatch(s + 1, p));
    }
    else
    {
        firstMatch = s[0] && (s[0] == p[0] || p[0] == '.');
        return  firstMatch && isMatch(s + 1, p + 1);
    }
}


int     main(int argc, char **argv)
{
    printf("%d\n", isMatch(argv[1],argv[2]));
}
