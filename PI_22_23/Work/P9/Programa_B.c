#include <stdio.h>
#include <assert.h>
#include <math.h>

const char *author = ("Ricardo Aleluia");

int bigger_array(int *a, int contador)
{
	int bigger = a[0];
	for(int i = 0; i < contador; i++)
	{
		if (a[i] > bigger)
		{
			bigger = a[i];
		}
	}
	return bigger;
}

int smaller_array(int *a, int contador)
{
	int smaller = a[0];
	for(int i = 0; i < contador; i++)
	{
		if (a[i] < smaller)
		{
			smaller = a[i];
		}
	}
	return smaller;
}

int ints_all_equal(int *a, int contador, int i)
{
	int resultado;
	if(bigger_array(a, contador) == smaller_array(a, contador))
	{
		resultado = 1;
	}
	else
	{
		resultado = 0;
	}
	return resultado;
}

void test(void)
{
	int a[1000] = {};
	int contador = 0;
	int i = 0;
	while(scanf("%d", &a[i]) != EOF)
	{
		i++;
		contador++;
	}
	printf("%d\n", ints_all_equal(a, contador, i));
}

void asserts(void)
{
	int a1[1] = {1};
	assert(ints_all_equal(a1, 1, 1) == 1);
	int a2[2] = {2,2};
	assert(ints_all_equal(a2, 2, 2) == 1);
	int a3[3] = {1,2,3};
	assert(ints_all_equal(a3, 3, 3) == 0);
	int a4[4] = {1,2,3,4};
	assert(ints_all_equal(a4, 4, 4) == 0);
}

int main(void)
{
	asserts();
	test();
	return 0;
}