#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = ("Ricardo Aleluia");

int lenght(const char *subsequencia)
{
	int y = 0;
	for(int i = 0; subsequencia[i] != '\0'; i++)
	{
		y++;
	}
	return y;
}

int sequences(const char *subsequencia, const char *nome)
{
	int u = 0;
	for(int i = 0; nome[i] != '\0'; i++)
	{
		if(subsequencia[u] == nome[i])
		{
			u++;
		}
	}
	return u;
}

void test(void)
{
	char subsequencia[1000] = {};
	char nome[1000] = {};
	while(scanf("%s%s", subsequencia, nome) != EOF)
	{
		int size_1 = lenght(subsequencia);
		int size_2 = sequences(subsequencia, nome);
		if(size_1 == size_2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}

int main(void)
{
	test();
}