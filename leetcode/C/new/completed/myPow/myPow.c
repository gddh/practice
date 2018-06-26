#include <stdio.h>

double myPow(double x, int n){
    double result;
    int neg;

    neg = (n < 0) ? 1 : 0;
    result = 1;
    while (n != 0)
    {
        if (n % 2 == 1 || n % 2 == -1)
            result = x * result;
        x = x * x;
        n = n / 2;
    }
    if (neg == 1)
        result = 1 / result;
    return result;
}

int main(int argc, char **argv)
{
    printf("result is: %f\n", myPow(2, -3));
}
