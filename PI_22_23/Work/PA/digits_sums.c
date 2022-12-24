#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int sum(int x)
{
	int resultado;
	if(x < 10)
	{
		resultado = x;
	}
	else
	{
		resultado = x % 10 + sum(x / 10);
	}
	return resultado;
}

int digits_sums(int *a, int n, int *b)
{
	int y = 0;
	for(int i = 0; i < n; i++)
	{
		assert(a[i] >= 0);
		b[y++] = sum(a[i]);
	}
	return y;
}

void test(void)
{
	int a[1000] = {};
	int b[1000] = {};
	int n = ints_get_until(-1, a);
	digits_sums(a, n, b);
	ints_println_special(b, n);
}

void asserts(void)
{
	int a1[4] = {1,2,3,4};
	int b1[1000] = {};
	assert(digits_sums(a1, 4, b1) == 4);
	assert(b1[0] == 1);
	assert(b1[1] == 2);
	assert(b1[2] == 3);
	assert(b1[3] == 4);
	int a2[4] = {15,25,35,45};
	int b2[1000] = {};
	assert(digits_sums(a2, 4, b2) == 4);
	assert(b2[0] == 6);
	assert(b2[1] == 7);
	assert(b2[2] == 8);
	assert(b2[3] == 9);
	int a3[5] = {3,6,9,12,15};
	int b3[1000];
	assert(digits_sums(a3, 5, b3) == 5);
	assert(b3[0] == 3);
	assert(b3[1] == 6);
	assert(b3[2] == 9);
	assert(b3[3] == 3);
	assert(b3[4] == 6);
	int a4[10] = {5,10,15,20,25,30,35,40,45,50};
	int b4[1000];
	assert(digits_sums(a4, 10, b4) == 10);
	assert(b4[0] == 5);
	assert(b4[1] == 1);
	assert(b4[2] == 6);
	assert(b4[3] == 2);
	assert(b4[4] == 7);
	assert(b4[5] == 3);
	assert(b4[6] == 8);
	assert(b4[7] == 4);
	assert(b4[8] == 9);
	assert(b4[9] == 5);
}

int main(void)
{
	asserts();
	test();
	return 0;
}