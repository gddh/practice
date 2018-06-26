#include <stdio.h>

int     isMatch(char* s, char* p) 
{
    if (s[0] == '\0' && p[0] == '\0')
        return 1;
    else if (p[0] != '\0' && p[1] == '*' &&
            (p[0] == s[0] || (p[0] == '.' && s[0] != '\0')))
        return isMatch(s + 1, p) || isMatch(s, p + 2);
    else if (p[0] != '\0' && p[1] == '*')
        return isMatch(s, p + 2);
    else if (s[0] != p[0] && 
        (p[0] != '.' || (p[0] == '.' && s[0] == '\0')))
        return 0;
    else
        return isMatch(s + 1, p + 1);
}

int     main(int argc, char **argv)
{
    printf("%d\n", isMatch(argv[1], argv[2]));
}
