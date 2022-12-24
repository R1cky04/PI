#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

double sum_powers_from(double x, double y, int n)
{
	int k = 0;
	double sum = 0;
	while(n != k)
	{
		sum = sum + pow((k + x), y);
		++k;
	}
	return sum;
}

void teste(void)
{
	double x;
	double y;
	int n;
	double result;
	while(scanf("%lf%lf%d", &x, &y, &n) != EOF)
	{
		result = sum_powers_from(x, y, n);
		printf("%f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}