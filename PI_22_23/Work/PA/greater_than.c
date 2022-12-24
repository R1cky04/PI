#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");

int greater_than(int *a, int n, int *b, int x)
{
	int y = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > x)
		{
			b[y++] = a[i];
		}
	}
	return y;
}

void test(void)
{
	int a[1000] = {};
	int x;
	int b[1000] = {};
	int n = ints_get_until(-1,a);
	while(scanf("%d", &x) != EOF)
	{
		ints_println_special(b, greater_than(a, n, b, x));
	}
}

void asserts(void)
{
	int a1[4] = {1,2,3,4};
	int b1[1000] = {};
	int x1 = 3;
	assert(greater_than(a1, 4, b1, x1) == 1);
	assert(b1[0] == 4);
	int a2[3] = {1,2,3};
	int b2[1000] = {};
	int x2 = 1;
	assert(greater_than(a2, 3, b2, x2) == 2);
	assert(b2[0] == 2);
	assert(b2[1] == 3);
	int a3[6] = {1,2,3,4,5,6};
	int b3[1000] = {};
	int x3 = 3;
	assert(greater_than(a3, 6, b3, x3) == 3);
	assert(b3[0] == 4);
	assert(b3[1] == 5);
	assert(b3[2] == 6);
	int a4[10] = {1,2,3,4,5,6,7,8,9,10};
	int b4[1000] = {};
	int x4 = 1;
	assert(greater_than(a4, 10, b4, x4) == 9);
	assert(b4[0] == 2);
	assert(b4[1] == 3);
	assert(b4[2] == 4);
	assert(b4[3] == 5);
	assert(b4[4] == 6);
	assert(b4[5] == 7);
	assert(b4[6] == 8);
	assert(b4[7] == 9);
	assert(b4[8] == 10);
}

int main(void)
{
	asserts();
	test();
	return 0;
}