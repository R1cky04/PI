#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int max(int numeroA, int numeroB)
{
	return numeroA >= numeroB ? numeroA : numeroB;
}

double price_total(double price, int numeroA, int numeroB)
{
	double total_price = 0;
	int blusas = numeroA + numeroB;
	if(numeroA + numeroB > 3)
	{
		total_price = (((numeroA - (blusas/3))*(price - (price * 0.15) - (price * 0.10))) + (numeroB*(price - (price * 0.15)))) / blusas;
	}
	else if (numeroA + numeroB < 3)
	{
		total_price = numeroA*(price - (price * 0.15) - (price * 0.10)) + (numeroB*(price - (price * 0.15))) / blusas;
	}
	else
	{
		
		total_price = (max(numeroA, numeroB) - blusas/3) * (price - (price * 0.15)) / blusas;	
	}
	return round(total_price*100)/100;
}

void teste(void)
{
	double price;
	int numeroA;
	int numeroB;
	while(scanf("%lf%d%d", &price, &numeroA, &numeroB) != EOF)
	{
		double result = price_total(price, numeroA, numeroB);
		printf("%0.6f\n", result);
		
	}

}

int main(void)
{
	teste();
	return 0;
}