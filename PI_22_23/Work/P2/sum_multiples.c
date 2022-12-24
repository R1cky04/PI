#include <stdio.h>
const char *author = "Ricardo_Aleluia";

int sum_multiples(int r, int n)
{
    int multiple;
    int soma = 0;
    int k = 0;
    while(n != k)
    {
        multiple = r * k;
        soma = multiple + soma;
        ++k;
    }
    return soma;
}

void teste(void)
{
    int r, n;
    while(scanf("%d%d", &r , &n) != EOF)
    {
        int result = sum_multiples(r, n);
        printf("%d\n", result);
    }
}

int main(void)
{
    teste();
    return 0;
}
