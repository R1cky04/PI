#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int  ints_take(int *a, int n, int x, int *b)
{
	int u = 0;
	for(int i = 0; i < n; i++)
	{
		if(i < x && x > 0)
		{
			b[u++] = a[i];
		}
	}
	return u;
}

void test(void)
{
	int a[1000] = {};
	int b[1000] = {};
	int x;
	int n = ints_get_until(-1,a);
	while(scanf("%d", &x) != EOF)
	{
		ints_println_special(b, ints_take(a, n, x, b));
	}
}

void asserts(void)
{
	int a1[5] = {1,2,3,4,5};
	int x1 = 3;
	int b1[1000];
	assert(ints_take(a1, 5, x1, b1) == 3);
	assert(b1[0] == 1);
	assert(b1[1] == 2);
	assert(b1[2] == 3);
	int a2[4] = {1,2,3,4};
	int x2 = 1;
	int b2[1000];
	assert(ints_take(a2, 4, x2, b2) == 1);
	assert(b2[0] == 1);
	int a3[10] = {10,20,30,40,50,60,70,80,90,100};
	int x3 = 10;
	int b3[1000];
	assert(ints_take(a3, 10, x3, b3) == 10);
	assert(b3[0] == 10);
	assert(b3[1] == 20);
	assert(b3[2] == 30);
	assert(b3[3] == 40);
	assert(b3[4] == 50);
	assert(b3[5] == 60);
	assert(b3[6] == 70);
	assert(b3[7] == 80);
	assert(b3[8] == 90);
	assert(b3[9] == 100);
	int a4[3] = {1,2,3};
	int x4 = 2;
	int b4[1000];
	assert(ints_take(a4, 2, x4, b4) == 2);
	assert(b4[0] == 1);
	assert(b4[1] == 2);
}

int main(void)
{
	asserts();
	test();
	return 0;
}