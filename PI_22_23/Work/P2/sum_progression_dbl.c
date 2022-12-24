#include <stdio.h>
const char *author = ("Ricardo Aleluia");

double sum_progression_dbl(double x0, double r, int n)
{
    return n == 0 ? 0 : (sum_progression_dbl(x0 + r, r, n-1) + x0);
}

void teste(void)
{
    double x0;
    double r;
    int n;
    while(scanf("%lf%lf%d", &x0, &r, &n) != EOF)
    {
        double result = sum_progression_dbl(x0, r, n);
        printf("%f\n", result);
    }
}

int main(void)
{
    teste();
    return 0;
}