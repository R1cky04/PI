#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

const double eth = 1449.87;
const double xmr = 146.78;
const double ltc = 55.86;

double bitcoin(int x, double n)
{
	double euro;
	if(x == 1)
		euro = n * eth;
	else if(x == 2)
	{
		euro = n * xmr;
	}
	else
	{
		euro = n * ltc;
	}
	return euro;
}

double conversion(double euro)
{
	double dolar;
	dolar = euro * 1.02;
	return dolar;
}

void teste(void)
{
	int x;
	double n;
	double euro;
	double dolar;
	while(scanf("%d%lf", &x, &n) != EOF)
	{
		euro = bitcoin(x, n);
		dolar = conversion(euro);
		printf("%.2f\n", euro);
		printf("%.3f\n", dolar);
	}
}

int main(void)
{
	teste();
	return 0;
}
