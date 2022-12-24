#include <stdio.h>
#include <assert.h>
#include <math.h>

const char *author = ("Ricardo Aleluia");


int sum_positions_minus_odd_positions(int *a, int contador, int i)
{
	int sum_array = 0;
	int sum_odds = 0;
	for(int i = 0; i < contador; i++)
	{
		sum_array =  sum_array + a[i];
		if(i % 2 != 0)
		{
			sum_odds = sum_odds + a[i];
		}
	}
	return (sum_array - sum_odds);
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
	printf("%d\n", sum_positions_minus_odd_positions(a, contador, i));
}

void asserts(void)
{
	int a1[1] = {1};
	assert(sum_positions_minus_odd_positions(a1, 1, 1) == 1);
	int a2[2] = {1,2};
	assert(sum_positions_minus_odd_positions(a2, 2, 2) == 1);
	int a3[3] = {1,2,3};
	assert(sum_positions_minus_odd_positions(a3, 3, 3) == 4);
	int a4[4] = {1,2,3,4};
	assert(sum_positions_minus_odd_positions(a4, 4, 4) == 4);
}

int main(void)
{
	asserts();
	test();
	return 0;
}

