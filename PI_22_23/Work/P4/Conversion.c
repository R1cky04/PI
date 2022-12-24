#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int conversion (int x, int y)
{
	int y = 1;
	return x <100 ? round(x)*y : conversion(x/10, y*10);
}

void teste(void)
{
	int result;
	int x;
	int y = 1;
	while(scanf("%d", &x) != EOF)
	{
		result = conversion(x, y);
		printf("%d\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
}