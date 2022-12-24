#include <stdio.h>
#include <math.h>
const char *author = "Ricardo_Aleluia";

double sum_powers_from(double x, double n)
{
	double soma = 0;
	double k = 0;
	while(n != k)
	{
		soma = pow(x + k, 2) + soma;
		++k;
	}
	return soma;
}

void teste(void)
{
	double x;
	double n;
	while(scanf("%lf%lf", &x, &n) != EOF)
	{
		double result = sum_powers_from(x, n);
		printf("%f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}