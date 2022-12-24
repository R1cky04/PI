#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <string.h>
#include "our_ints.h"
#include "our_doubles.h"

const char *author = ("Ricardo Aleluia");


int gas(const double *distancias, const double *valor_praticado, int n, int m, double price)
{
	double melhor = price / valor_praticado[0] - 2 * (distancias[0] * 6.2 / 100);
	int indice = 0;
	for(int i = 0; i < n && i < m; i++)
	{
		double litros = price / valor_praticado[i] - 2 * (distancias[i] * 6.2 / 100);
		if(litros > melhor)
		{
			melhor = litros;
			indice = i;
		}
	}
	return indice;
}

double gas_liters(const double *distancias, const double *valor_praticado, int n, int m, double price)
{
	double litros = 0;
	int i = gas(distancias, valor_praticado, n, m, price);
	litros = price / valor_praticado[i] - 2 * (distancias[i] * 6.2 / 100);
	return litros;
}

void test_fuel(void)
{
	double distancias[1000];
	int n = doubles_get_until(-1, distancias);    
	double valor_praticado[1000];
	int m = doubles_get_until(-1, valor_praticado);    
	double price;
	while(scanf("%lf", &price) != EOF)
	{
		printf("%d %.1f\n", gas(distancias, valor_praticado, n, m, price), gas_liters(distancias, valor_praticado, n, m, price));
	}
}

void unit_tests_gas(void)
{
	double distancias[1000] = {7.2, 15.4, 16.3, 22.5, 17.9, 35.23, 2.4};
	double valor_praticado[1000] = {1.629, 1.573, 1.654, 1.618, 1.622, 1.476, 1.712};
	assert(gas(distancias, valor_praticado, 7, 7, 50) == 1);
	assert(gas_liters(distancias, valor_praticado, 7, 7, 50) == 29.9);
	assert(gas(distancias, valor_praticado, 7, 7, 10) == 6);
	assert(gas_liters(distancias, valor_praticado, 7, 7, 10) == 5.5);
	assert(gas(distancias, valor_praticado, 7, 7, 25) == 0);
	assert(gas_liters(distancias, valor_praticado, 7, 7, 25) == 14.5);
}

int main(void)
{
	test_fuel();
}
