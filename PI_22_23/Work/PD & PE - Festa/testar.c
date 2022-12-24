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
///////////////////////////////////////////////////////////////////////////////////////////////////////

double doubles_exchange(double *km_percorridos_ordenado, int x, int y)
{
	int m = km_percorridos_ordenado[x];
	km_percorridos_ordenado[x] = km_percorridos_ordenado[y];
	km_percorridos_ordenado[y] = m;
	return 0;
}

double doubles_isort_combat(double *km_percorridos, int counter)
{
	for(int i = 0; i < (counter/3); i++)
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
	doubles_isort_combat(km_percorridos, counter);
	return y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema A

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

double med_km(const double *stats, int counter, double *km_percorridos, int h) // mediana dos kilometros percorridos
{
	double mediana = 0;
	mediana = (km_percorridos[(h - 1) / 2] + km_percorridos[h / 2]) / 2;
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
	printf("%.2f %.2f %.2f %.2f\n", avg_km(stats, counter), mode_km(stats, counter), med_km(stats, counter, km_percorridos, h), total_weight(stats, counter));
}

int main(void)
{
	test_worldcup();
	return 0;
}