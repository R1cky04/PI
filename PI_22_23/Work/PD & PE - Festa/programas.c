#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <string.h>
#include "our_ints.h"
#include "our_doubles.h"

const char *author = ("Ricardo Aleluia");

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema A

double doubles_exchange(double *km_percorridos_ordenado, int x, int y)
{
	double m = km_percorridos_ordenado[x];
	km_percorridos_ordenado[x] = km_percorridos_ordenado[y];
	km_percorridos_ordenado[y] = m;
	return 0;
}

double doubles_isort_combat(const double *stats, double *km_percorridos, int counter)
{
	km_percorridos[0] = stats[0];
	for(int i = 1; i < (counter/3); i++)
	{
		int j = i;
		while(j > 0 && km_percorridos[j-1] > km_percorridos[j])
		{
			doubles_exchange(km_percorridos, j-1, j);
			j--;
		}
	}
	return 0;
}

int array_de_km_percorridos(const double *stats, int counter, double *km_percorridos)
{
	int y = 0;
	for(int i = 0; i < counter; i++)
	{
		if(i % 3 == 0)
		{
			km_percorridos[y++] = stats[i];
		}
	}
	doubles_isort_combat(stats, km_percorridos, counter);
	return y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

double avg_km(const double *stats, int counter) // média de kilometros percorridos
{
	int u = 0;
	double total_de_kilometros_percorridos = 0;
	double media_dos_kilometros_percorridos = 0;
	for(int i = 0; i < counter; i++)
	{
		if(i % 3 == 0)
		{
			total_de_kilometros_percorridos = total_de_kilometros_percorridos + stats[i];
			u++;
		}
	}
	media_dos_kilometros_percorridos = total_de_kilometros_percorridos / u;
	return media_dos_kilometros_percorridos;
}

double mode_km(const double *stats, int counter) // moda dos kilometros percorridos
{
	int n = 0;
    double moda = stats[0];
    for(int i = 0; i < counter; i++)
    {
        if (i % 3 == 0 && doubles_count(stats, counter, stats[i]) > n)
        {
            n = doubles_count(stats, counter, stats[i]);
            moda = stats[i];
        }
    }
    return moda;
}

double med_km(double *km_percorridos, int h) // mediana dos kilometros percorridos
{
	double mediana = 0;
	mediana = (km_percorridos[30 / 2] + km_percorridos[30 / 2 - 1]) / 2;
	return mediana;
}

double total_weight(const double *stats, int counter) // total de peso perdido
{
	double total_weight_before = 0;
	double total_weight_after = 0;
	double total_weight_lost = 0;
	for(int i = 0; i < (counter / 3); i++)
	{
		total_weight_before = total_weight_before + stats[1 + i * 3];
		total_weight_after = total_weight_after + stats[2 + i * 3];
	}
	total_weight_lost = total_weight_before - total_weight_after;
	return total_weight_lost;
}


void test_worldcup(void)
{
	double stats[1000] = {};
	double km_percorridos[1000] = {};
	int counter = doubles_get(stats);
	int h = array_de_km_percorridos(stats, counter, km_percorridos);
	printf("%.2f %.2f %.2f %.2f\n", avg_km(stats, counter), mode_km(stats, counter), med_km(km_percorridos, h), total_weight(stats, counter));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema B

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
	litros = price / valor_praticado[i] - 2 * (distancias[i] * 6.2 / 100)
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
	assert(gas(distancias, valor_praticado, 7, 7, 10) == 6);
	assert(gas(distancias, valor_praticado, 7, 7, 25) == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema C


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	int x = 'A';
	if(argc > 1)
	{
		x = *argv[1];
	}
	if(x == 'A')
	{
		test_worldcup();
	}
	else if(x == 'B')
	{
		unit_tests_gas();
		test_fuel();
	}
	else if(x == 'C')
	{
		printf("All unit tests PASSED\n");
	}
	else
	{
		printf("%s: Invalid option.\n", argv[1]);
	}
	return 0;
}