#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int dias(int y)
{
	while(y > 0)
	{
		y = y - 7;
	}
	return (y + 7);
}

int mesas(int y)
{
	if (y == 1)
		return 6;
	else
	{
		return (4*(y - 2)) + 10;
	}
}

int funcao(int x, int y)
{
	if(x == 1)
	{
		return dias(y);
	}
	else
	{
		return mesas(y);
	}
}

void test(void)
{
	int x;
	int y;
	int result;
	while(scanf("%d%d", &x, &y) != EOF)
	{
		result = funcao(x, y);
		printf("%d\n", result);
	}
}

int main(void)
{
	test();
	return 0;
}