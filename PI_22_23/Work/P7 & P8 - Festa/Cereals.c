#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");


const double lat_lisboa = 38.72;
const double long_lisboa = 9.14;

double distancia_aproximada(double lat_origem, double long_origem)
{
	return sqrt((pow(lat_lisboa - lat_origem, 2)) + pow(long_lisboa - long_origem, 2)) * 100;
}


double distancia_corrigida(double lat_origem, double long_origem)
{
	double resultado = 0;
	if (distancia_aproximada(lat_origem, long_origem) <= 1000) // terrestre
	{
		resultado = distancia_aproximada(lat_origem, long_origem) + 0.12 * distancia_aproximada(lat_origem, long_origem);
	}
	else if (distancia_aproximada(lat_origem, long_origem) > 1000 && distancia_aproximada(lat_origem, long_origem) <= 3000) // aerea
	{
		resultado = distancia_aproximada(lat_origem, long_origem) - 0.25 * distancia_aproximada(lat_origem, long_origem); 
	}
	else // maritima
	{
		resultado = distancia_aproximada(lat_origem, long_origem) + 0.18 * distancia_aproximada(lat_origem, long_origem);
	}
 return resultado;
}


void test(void)
{
	double lat_origem;
	double long_origem;
	while(scanf("%lf%lf", &lat_origem, &long_origem) != EOF)
	{
		if(distancia_aproximada(lat_origem, long_origem) <= 1000)
		{
			printf("%.3f VT %0.3f\n", distancia_aproximada(lat_origem, long_origem), distancia_corrigida(lat_origem, long_origem)); // terrestre
		}
		else if(distancia_aproximada(lat_origem, long_origem) > 1000 && distancia_aproximada(lat_origem, long_origem) <= 3000)
		{
			printf("%.3f VA %0.3f\n", distancia_aproximada(lat_origem, long_origem), distancia_corrigida(lat_origem, long_origem)); // aereo
		}
		else
		{
			printf("%.3f VM %0.3f\n", distancia_aproximada(lat_origem, long_origem), distancia_corrigida(lat_origem, long_origem)); // maritimo
		}
	}
}

int main(void)
{
	test();
	return 0;
}