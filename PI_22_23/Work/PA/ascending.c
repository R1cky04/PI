#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");

int ints_ascending(int *a, int n, int *b)
{
	int u = 0;
	int max = a[0];
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= max)
		{
			max = a[i];
			b[u++] = a[i];
		}
	}
	return u;
}

void test(void)
{
	int a[1000] = {};
	int b[1000] = {};
	int n = ints_get_until(-1,a);
	ints_println_special(b, ints_ascending(a, n, b));
}

void asserts(void)
{
	int a1[5] = {1,2,3,4,5};
	int b1[1000];
	assert(ints_ascending(a1, 5, b1) == 5);
	assert(b1[0] == 1);
	assert(b1[1] == 2);
	assert(b1[2] == 3);
	assert(b1[3] == 4);
	assert(b1[4] == 5);
	int a2[4] = {4,3,2,1};
	int b2[1000];
	assert(ints_ascending(a2, 4, b2) == 1);
	assert(b2[0] == 4);
	int a3[14] = {3,1,8,2,4,5,7,9,5,9,4,15,13,11};
	int b3[1000];
	assert(ints_ascending(a3, 14, b3) == 5);
	assert(b3[0] == 3);
	assert(b3[1] == 8);
	assert(b3[2] == 9);
	assert(b3[3] == 9);
	assert(b3[4] == 15);
	int a4[6] = {1,2,3,3,2,1};
	int b4[1000];
	assert(ints_ascending(a4, 6, b4) == 4);
	assert(b4[0] == 1);
	assert(b4[1] == 2);
	assert(b4[2] == 3);
	assert(b4[2] == 3);
}

int main(void)
{
	asserts();
	test();
	return 0;
}