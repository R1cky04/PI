#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int max_index(double *a, int contador, int i)
{
	double maior = a[0];
	int indice_max = 0;
	for(int i = 0; i < contador; i++)
	{
		if (a[i] > maior)
		{
			maior = a[i];
			indice_max = i;
		}
	}
	return indice_max;
}

int min_index(double *a, int contador, int i)
{
	double menor = a[0];
	int indice_min = 0;
	for(int i = 0; i < contador; i++)
	{
		if (a[i] < menor)
		{
			menor = a[i];
			indice_min = i;
		}
	}
	return indice_min;
}

double sum(double *a, int contador, int i)
{
	return a[max_index(a,contador, i)]  + a[min_index(a,contador, i)];
}

void test(void)
{
	double a[20];
	int contador = 0;
	int i = 0;
	while(scanf("%lf", &a[i]) != EOF)
	{
		i++;
		contador++;
	}
	printf("%d\n%d\n%f\n", max_index(a, contador, i), min_index(a, contador, i), sum(a, contador, i));
}

int main(void)
{
	test();
	return 0;
}
