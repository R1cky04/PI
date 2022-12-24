#include <stdio.h>
const char *author = "Ricardo_Aleluia";
int succ(int x); 
int pred(int x); 
int is_zero(int x); 
int is_pos(int x);

int difference(int x, int y)
{
	return is_zero(y) ? x:difference(pred(x), pred(y));
}

int less_equal(int x, int y)
{
	return is_pos(difference(y, x)) ? 1 : 0;
}

int sum(int x, int y)
{
	return is_zero(y) ? x :sum(succ(x), pred(y));
}

int twice(int x)
{
	return sum(x, x);
}

int half(int x)
{
	return less_equal(twice(x), w) ? x : half(pred(x));
}

int w;
int main(void)
{
	int x;
	scanf("%d", &x);
	w = x;
	int z = half(x);
	printf("%d\n", z);
	return 0;
}