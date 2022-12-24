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

int ints_second_max(int *a, int contador)
{
	int second_bigger = a[0];
	for(int i = 0; i < contador; i++)
	{
		if(a[i] > second_bigger  && a[i] < bigger_array(a, contador))
		{
			second_bigger = a[i];
		}
	}
	return second_bigger;
}

void test(void)
{
	int a[1000] = {};
	int i = 0;
	int contador = 0;
	while(scanf("%d", &a[i]) != EOF)
	{
		i++;
		contador++;
	}
	printf("%d\n", ints_second_max(a, contador));
}

void assers(void)
{
	int a1[2] = {1,2};
	assert(ints_second_max(a1, 2) == 1);
	int a2[3] = {1,2,3};
	assert(ints_second_max(a2, 3) == 2);
	int a3[4] = {1,2,3,4};
	assert(ints_second_max(a3, 4) == 3);
	int a4[5] = {1,2,3,4,5};
	assert(ints_second_max(a4, 5) == 4);
}

int main(void)
{
	assers();
	test();
	return 0;
}