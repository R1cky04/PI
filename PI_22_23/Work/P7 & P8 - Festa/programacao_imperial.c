#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");


const int pontos_por_programa = 3;

int soma_dos_programas(const int *contests, int n)
{
	int i = n / 2;
	int sum_programs = 0;
	while(i < n)
	{
		sum_programs = sum_programs + contests[i];
		i++;
	}
	return sum_programs;
}


int total_points(const int *contests, int n)
{
	int i = 0;
	int pontos_bonus = 0;
	while(i < n / 2)
	{
		if(2 * contests[ i + n / 2] >= contests[i])
		{
			pontos_bonus++;
		}
		i++;
	}
	return soma_dos_programas(contests, n) * pontos_por_programa + pontos_bonus;
}


int ints_get(int *contests)
{
	int k;
	int indices = 0;
	while(scanf("%d", &k) != EOF)
	{
		contests[indices++] = k;
	}
	return indices;
}

void test()
{
	int result;
	int contests[1000] = {};
	int n = ints_get(contests);
	result = total_points(contests, n);
	printf("%d\n", result);
}

int main(void)
{
	test();
	return 0;
}