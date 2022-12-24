#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

double sum_inverses(double n)
{
	double sum = 0;
	int k = 1;
	while(n >= k)
	{
		sum = pow((k), (-1)) + sum;
		++k;
	}
	return sum;
}

void teste(void)
{
	double result;
	double n;
	while(scanf("%lf", &n) != EOF)
	{
		result = sum_inverses(n);
		printf("%f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}