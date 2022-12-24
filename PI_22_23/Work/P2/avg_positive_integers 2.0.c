#include <stdio.h>
const char *author = "Ricardo_Aleluia";

double sum_positive_integers(int x)
{
	int contador = x;
	return contador == 0 ? 0 : x + sum_positive_integers(x-1);
}

double avg_positive_integers(int x)
{
	return x == 0 ? 0 : (sum_positive_integers(x) / x);
}

void teste(void)
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		double result = avg_positive_integers(x);
		printf("%f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}
