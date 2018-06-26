#include <stdio.h>

int unique_substring(char c_start, char c_end, int *p)
{
    c_start = c_start - ' ';
    c_end = c_end -' ';
    if (p[c_end] > 0 || (p[c_end] == p[c_start] && c_end != c_start))
    {
        p[c_start] = 0;
        return 0;
    }
    else
    {
        p[c_end] = 1;
        return 1;
    }
}

int lengthOfLongestSubstring(char* s)
{
    int start;
    int end;
    int max_count;
    int p[137] = {0};

    start = 0;
    end = 0;
    max_count = 0;
    while (s[end] != '\0')
    {
        if (unique_substring(s[start], s[end], p))
            end = end + 1;
        else 
            start = start + 1;
        if (end - start > max_count)
            max_count = end - start;
    }
    return max_count;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("%d",lengthOfLongestSubstring(argv[1]));
    }
    printf("\n");
}
