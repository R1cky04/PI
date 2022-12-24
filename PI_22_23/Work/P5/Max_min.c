#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

double max(double *a, int contador)
{
	double maior = a[0];
	for(int i = 0; i < contador; i++)
	{
		if (a[i] > maior)
		{
			maior = a[i];
		}
	}
	return maior;
}

double min(double *a, int contador)
{
	double menor = a[0];
	for(int i = 0; i < contador; i++)
	{
		if (a[i] < menor)
		{
			menor = a[i];
		}
	}
	return menor;
}

double difference(double *a, int contador)
{
	return max(a, contador) - min(a, contador);
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
	printf("%f\n%f\n%f\n", max(a, contador), min(a, contador), difference(a, contador));
}

int main(void)
{
	test();
	return 0;
}