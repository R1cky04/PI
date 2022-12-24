#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int ints_unaccumulate(int *a, int n, int *b)
{
	int u = 0;
	for(int i = 1; i < n; i++)
	{
		b[u++] = a[i] - a[i-1];
	}
	return u;
}

void test(void)
{
	int a[1000] = {};
 	int b[1000] = {};
	int n = ints_get_until(-1,a);
	ints_println_special(b, ints_unaccumulate(a, n, b));
}

void asserts(void)
{
	int a1[6] = {0,1,2,3,4,5};
	int b1[1000];
	assert(ints_unaccumulate(a1, 6, b1) == 5);
	assert(b1[0] == 1);
	assert(b1[1] == 1);
	assert(b1[2] == 1);
	assert(b1[3] == 1);
	assert(b1[4] == 1);
	int a2[5] = {0,4,3,2,1};
	int b2[1000];
	assert(ints_unaccumulate(a2, 5, b2) == 4);
	assert(b2[0] == 4);
	assert(b2[1] == -1);
	assert(b2[2] == -1);
	assert(b2[3] == -1);
	int a3[7] = {0,5,6,10,11,14,18};
	int b3[1000];
	assert(ints_unaccumulate(a3, 7, b3) == 6);
	assert(b3[0] == 5);
	assert(b3[1] == 1);
	assert(b3[2] == 4);
	assert(b3[3] == 1);
	assert(b3[4] == 3);
	assert(b3[5] == 4);
	int a4[8] = {0,1,2,3,3,2,1,0};
	int b4[1000];
	assert(ints_unaccumulate(a4, 8, b4) == 7);
	assert(b4[0] == 1);
	assert(b4[1] == 1);
	assert(b4[2] == 1);
	assert(b4[3] == 0);
	assert(b4[4] == -1);
	assert(b4[5] == -1);
	assert(b4[6] == -1);
}

int main(void)
{
	asserts();
	test();
	return 0;
}