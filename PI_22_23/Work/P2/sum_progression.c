#include <stdio.h>
const char *author = ("Ricardo Aleluia");

int sum_progression(int x0, int r, int n)
{
	int soma = 0;
	int progression;
	int k = 0;
	while(n != k)
	{
		progression = r * k;
		soma = (progression + x0) + soma;
		++k;
	}
	return soma;
}

void teste(void)
{
	int x0;
	int r;
	int n;
	while(scanf("%d%d%d", &x0, &r, &n) != EOF)
	{
		int result = sum_progression(x0, r, n);
		printf("%d\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}