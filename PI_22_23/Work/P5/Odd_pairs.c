#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int odd_pairs(int *a, int contador)
{
	int impar = 0;
	int par = 0;
	int sum = 0;
	int soma_pares = 0;
	int soma_impares = 0;
	for(int i = 0; i < contador; i++)
	{
		if(a[i] % 2 == 0)
		{
			sum = par + a[i];
			soma_pares = soma_pares + sum;
		}
		else 
		{
			sum = impar + a[i];
			soma_impares = soma_impares + sum;
		}

	}
	return (soma_pares - soma_impares);
}

void test(void)
{
	int result = 0;
	int contador = 0;
	int a[20] = {};
	int i = 0;
	while(scanf("%d", &a[i]) != EOF)
		{
			i++;
			contador++;
		}
	result = odd_pairs(a, contador);
	printf("%d\n", result);
}

int main(void)
{
	test();
	return 0;
}