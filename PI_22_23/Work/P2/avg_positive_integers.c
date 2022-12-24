#include <stdio.h>
const char *author = "Ricardo_Aleluia";

double avg_positive_integers(double x)
{
	double contador = x;
	double soma = 0;
	double z = 0;
	while (contador > z)
	{
		soma = soma + contador;
		contador = contador - 1; 
	}
	return soma = 0 ? 0 : (soma / x);
}

void avg_positive(void)
{
	int w;
	while(scanf("%d", &w) != EOF)
	{
		double result = avg_positive_integers(w);
	    printf("%f\n", result);
	}
}

int main(void)
{
	avg_positive();
	return 0;
}
