#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"

const char *author = ("Ricardo Aleluia");


int ints_find_triple(int *a, int n)
{
	int result = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == a[i+1] && a[i] == a[i+2])
		{
			result = i;
			i = i+n;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

void test(void)
{
	int a[1000] = {};
	int n = ints_get_until(-1,a);
	printf("%d\n", ints_find_triple(a, n));
}

void asserts(void)
{
	int a1[5] = {1,2,3,4,5};
	assert(ints_find_triple(a1,5) == -1);
	int a2[12] = {6,2,8,5,9,9,9,1,9,2,2,2};
	assert(ints_find_triple(a2,12) == 4);
	int a3[8] = {1,6,3,8,8,3,8,2};
	assert(ints_find_triple(a3,8) == -1);
	int a4[10] = {4,3,2,8,7,7,7,4,3,3};
	assert(ints_find_triple(a4,10) == 4);
}

int main(void)
{
	asserts();
	test();
	return 0;
}