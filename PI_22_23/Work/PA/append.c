#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int ints_append(const int *a, int n, const int *b, int m, int *c)
{
	int u = 0;
	int indice_do_b = 0;
	for(int i = 0; i < (n+m) ; i++)
	{
		if(i < n)
		{
			c[u++] = a[i];
		}
		else
		{
			c[u++] = b[indice_do_b++];
		}
	}
	return u;
}

void test(void)
{
	int a[1000] = {};
	int b[1000] = {};
	int c[1000] = {};
	int n = ints_get_until(-1,a);
	int m = ints_get_until(-1,b);
	ints_append(a, n, b, m , c);
	ints_println_special(c, ints_append(a, n, b, m, c));
	ints_append(b, n, a, m , c);
	ints_println_special(c, ints_append(b, m, a, n, c));
}

void asserts(void)
{
	int a1[5] = {1,2,3,4,5};
	int b1[3] = {1,2,3};
	int c1[1000];
	assert(ints_append(a1, 5, b1, 3, c1) == 8);
	assert(c1[0] == 1);
	assert(c1[1] == 2);
	assert(c1[2] == 3);
	assert(c1[3] == 4);
	assert(c1[4] == 5);
	assert(c1[5] == 1);
	assert(c1[6] == 2);
	assert(c1[7] == 3);
	assert(ints_append(b1, 3, a1, 5, c1) == 8);
	assert(c1[0] == 1);
	assert(c1[1] == 2);
	assert(c1[2] == 3);
	assert(c1[3] == 1);
	assert(c1[4] == 2);
	assert(c1[5] == 3);
	assert(c1[6] == 4);
	assert(c1[7] == 5);
	int a2[3] = {10,11,12};
	int b2[2] = {13,14};
	int c2[1000];
	assert(ints_append(a2, 3, b2, 2, c2) == 5);
	assert(c2[0] == 10);
	assert(c2[1] == 11);
	assert(c2[2] == 12);
	assert(c2[3] == 13);
	assert(c2[4] == 14);
	assert(ints_append(b2, 2, a2, 3, c2) == 5);
	assert(c2[0] == 13);
	assert(c2[1] == 14);
	assert(c2[2] == 10);
	assert(c2[3] == 11);
	assert(c2[4] == 12);
	int a3[2] = {50,60};
	int b3[1] = {70};
	int c3[1000];
	assert(ints_append(a3, 2, b3, 1, c3) == 3);
	assert(c3[0] == 50);
	assert(c3[1] == 60);
	assert(c3[2] == 70);
	assert(ints_append(b3, 1, a3, 2, c3) == 3);
	assert(c3[0] == 70);
	assert(c3[1] == 50);
	assert(c3[2] == 60);
	int a4[4] = {2,4,6,8};
	int b4[4] = {3,5,7,9};
	int c4[1000];
	assert(ints_append(a4, 4, b4, 4, c4) == 8);
	assert(c4[0] == 2);
	assert(c4[1] == 4);
	assert(c4[2] == 6);
	assert(c4[3] == 8);
	assert(c4[4] == 3);
	assert(c4[5] == 5);
	assert(c4[6] == 7);
	assert(c4[7] == 9);
	assert(ints_append(b4, 4, a4, 4, c4) == 8);
	assert(c4[0] == 3);
	assert(c4[1] == 5);
	assert(c4[2] == 7);
	assert(c4[3] == 9);
	assert(c4[4] == 2);
	assert(c4[5] == 4);
	assert(c4[6] == 6);
	assert(c4[7] == 8);
}

int main(void)
{
	asserts();
	test();
	return 0;
}