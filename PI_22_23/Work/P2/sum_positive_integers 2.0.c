#include <stdio.h>
const char *author = "Ricardo_Aleluia";

int sum_positive_integers(int x)
{
	int contador = x;
	return contador == 0 ? 0 : x + sum_positive_integers(x-1);
}

void teste(void)
{
	int x;
	while(scanf("%d", %x) =! EOF)
	{
		int result = sum_positive_integers(x);
		printf("%d", result);
	}
}

int main(void)
{
	teste();
	return 0;
}