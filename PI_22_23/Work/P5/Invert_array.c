#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

 
int invert_array(int *a, int i)
{
	int resultado;
	while(i != 0)
	{
		resultado = a[i-1];
		--i;
		printf("%d\n", resultado);
	}
	return 0;
}

void test(void)
{
	int a[20];
	int i = 0;
	while(scanf("%d", &a[i]) != EOF)
		{
			i++;
		}
	invert_array(a, i);
}	

int main(void)
{
	test();
	return 0;
}