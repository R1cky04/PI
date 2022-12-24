#include <stdio.h>
#include <assert.h>

const char *author = ("Ricardo Aleluia");

int multiplication_arrays(int *a, int counter, int *b)
{
	for(int i = 0; i < counter; i++)
	{
		if(i < counter)
		{
			b[i] = a[i] * a[i+1];
		}
	}
	b[counter-1] = a[counter-1] * a[counter-1];
	return 0;
}

int sum_arrays(int *a, int counter, int *b, int *c)
{
	int y = 0;
	int sum = 0;
	for(int i = 0; i < counter; i++)
	{
		c[y] = a[i] + b[i];
		sum = sum + c[y];
		y++;
	}
	return sum;
}

int ints_get(int *a)
{
    int k;
    int indices = 0;
    while(scanf("%d", &k) != EOF)
    {
        a[indices++] = k;
    }
    return indices;
}

void test(void)
{
	int a[1000] = {};
	int b[1000] = {};
	int c[1000] = {};
	int counter = ints_get(a);
	multiplication_arrays(a, counter, b);
	printf("%d", sum_arrays(a, counter, b, c));
	for(int i = 0; i < counter; i++)
	{
		printf(" %d", c[i]);
	}
	printf("\n");
}

void asserts(void)
{
	int a1[5] = {1,2,3,4,5};
	int b1[5] = {2,6,12,20,25};
	int c1[5] = {3,8,15,24,30};
	assert(sum_arrays(a1, 5, b1, c1) == 80);
	assert(c1[0] == 3);
	assert(c1[1] == 8);
	assert(c1[2] == 15);
	assert(c1[3] == 24);
	assert(c1[4] == 30);
	int a2[4] = {2,4,6,8};
	int b2[4] = {8,24,48,64};
	int c2[4] = {10,28,54,72};
	assert(sum_arrays(a2,4,b2,c2) == 164);
	assert(c2[0] == 10);
	assert(c2[1] == 28);
	assert(c2[2] == 54);
	assert(c2[3] == 72);
	int a3[3] = {10,20,30};
	int b3[3] = {200,600,900};
	int c3[3] = {210,620,930};
	assert(sum_arrays(a3,3,b3,c3) == 1760);
	assert(c3[0] == 210);
	assert(c3[1] == 620);
	assert(c3[2] == 930);
	int a4[2] = {100,200};
	int b4[2] = {20000,40000};
	int c4[2] = {20100,40200};
	assert(sum_arrays(a4,2,b4,c4) == 60300);
	assert(c4[0] == 20100);
	assert(c4[1] == 40200);
}

int main(void)
{
	asserts();
	test();
	return 0;
}