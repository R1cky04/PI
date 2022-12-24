#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

double sum_inverse_squares(double n)
{
	double sum = 0;
	int k = 1;
	while(k != n+1)
	{
		sum = sum + pow(pow(k, 2), (-1));
		++k;
	}
	return sum;
}

void teste(void)
{
	double n;
	double result;
	while(scanf("%lf", &n) != EOF)
	{
		result = sum_inverse_squares(n);
		printf("%f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;

}