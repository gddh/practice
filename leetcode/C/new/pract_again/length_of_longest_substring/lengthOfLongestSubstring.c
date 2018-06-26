#include <stdio.h>

int is_unique_substring(int start, int end, char *str)
{
    int i;
    int alphabet_array[127] = {0};

    while (start <= end)
    {
        i = str[start];
        if (alphabet_array[i] > 0)
            return 0;
        alphabet_array[i] = alphabet_array[i] + 1;
        start = start + 1;
    }
    return 1;
}

int lengthOfLongestSubstring(char* s) 
{
    int max_count;
    int start;
    int end;
    
    max_count = 0;
    start = 0;
    end = 0;
    while (s[end] != '\0')
    {
        if (!is_unique_substring(start, end, s))
            start = start + 1;
        else
            end = end + 1;
        if (end - start > max_count)
            max_count = end - start;

    }
    return max_count;
}

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("%d\n", lengthOfLongestSubstring(argv[1]));
}
