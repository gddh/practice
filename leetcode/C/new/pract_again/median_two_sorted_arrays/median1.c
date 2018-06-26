#include <stdio.h>

void    swap(int **p1, int *size1, int **p2, int *size2)
{
    int *tp;
    int tmp;

    tp = *p1;
    *p1 = *p2;
    *p2 = tp;

    tmp = *size1;
    *size1 = *size2;
    *size2 = tmp;
}

int     ft_max(int v1, int v2)
{
    if (v1 >= v2)
        return v1;
    return v2;
}

int     ft_min(int v1, int v2)
{
    if (v1 <= v2)
        return v1;
    return v2;
}

double  findMedianSortedArrays(int *n1, int n1Size, int *n2, int n2Size)
{
    int i;
    int j;
    int min_i;
    int max_i;
    int half_len;
    int max_left;
    int min_right;
    
    if (n2Size < n1Size)
        swap(&n1, &n1Size, &n2, &n2Size);
    min_i = 0;
    max_i = n1Size;
    half_len = (n1Size + n2Size + 1) / 2;
    while (min_i <= max_i)
    {
        i = (min_i + max_i) / 2;
        j = half_len - i;
        if (i > 0 && n2[j - 1] > n1[i])
            min_i = i + 1;
        else if (j > 0 && n1[i  - 1] > n2[j])
            max_i = i - 1;
        else
        {
            if (i == 0)
                max_left = n2[j - 1];
            else if (j == 0)
                max_left = n1[i - 1];
            else
                max_left = ft_max(n1[i - 1], n2[j - 1]);
            if ((n1Size + n2Size) % 2 == 1)
                return max_left;

            if (i == n1Size)
                min_right = n2[j];
            else if (j == n2Size)
                min_right = n1[i];
            else
                min_right = ft_min(n1[i], n2[j]);
            return (float)(max_left + min_right) / 2;
        }
    }
    return (0);
}

int     main(int argc, char **argv)
{
    int p[1] = {1};
    int p2[1] = {2};
    printf("%f\n",findMedianSortedArrays(p,1,p2,1));
}
