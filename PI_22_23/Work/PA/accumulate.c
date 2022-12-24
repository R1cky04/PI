#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int sum(int *a, int i)
{
	int sum = 0;
	for(int y = 0; i >= y; i--)
	{
		sum = sum + a[i];
	}
	return sum;
}

int ints_accumulate(int *a, int n, int *b)
{
	b[0] = 0;
	int u = 1;
	for(int i = 0; i < n; i++)
	{
		b[u++] = sum(a, i);
	}
	return u;
}

void test(void)
{
	int a[1000] = {};
 	int b[1000] = {};
	int n = ints_get_until(-1,a);
	ints_println_special(b, ints_accumulate(a, n, b));
}

void asserts(void)
{
 	int a1[5] = {1,2,3,4,5};
	int b1[1000];
	assert(ints_accumulate(a1, 5, b1) == 6);
	assert(b1[0] == 0);
	assert(b1[1] == 1);
	assert(b1[2] == 3);
	assert(b1[3] == 6);
	assert(b1[4] == 10);
	assert(b1[5] == 15);
	int a2[4] = {4,3,2,1};
	int b2[1000];
	assert(ints_accumulate(a2, 4, b2) == 5);
	assert(b2[0] == 0);
	assert(b2[1] == 4);
	assert(b2[2] == 7);
	assert(b2[3] == 9);
	assert(b2[4] == 10);
	int a3[6] = {5,1,4,1,3,4};
	int b3[1000];
	assert(ints_accumulate(a3, 6, b3) == 7);
	assert(b3[0] == 0);
	assert(b3[1] == 5);
	assert(b3[2] == 6);
	assert(b3[3] == 10);
	assert(b3[4] == 11);
	assert(b3[5] == 14);
	assert(b3[6] == 18);
	int a4[6] = {1,2,3,3,2,1};
	int b4[1000];
	assert(ints_accumulate(a4, 6, b4) == 7);
	assert(b4[0] == 0);
	assert(b4[1] == 1);
	assert(b4[2] == 3);
	assert(b4[3] == 6);
	assert(b4[4] == 9);
	assert(b4[5] == 11);
	assert(b4[6] == 12);
}

int main(void)
{
	asserts();
	test();
	return 0;
}