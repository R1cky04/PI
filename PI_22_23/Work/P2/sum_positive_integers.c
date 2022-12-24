#include <stdio.h>
const char *author = "Ricardo_Aleluia";

int sum_positive_integers(int x)
{
	int contador = x;
	int soma = 0;
	int z = 0;
	while (contador > z)
	{
		soma = soma + contador;
		contador = contador - 1; 
	}
	return soma;
}

void sum_positive(void)
{
	int w;
	while(scanf("%d", &w) != EOF)
	{
		int result = sum_positive_integers(w);
	    printf("%d\n", result);
	}
}

int main(void)
{
	sum_positive();
	return 0;
}
