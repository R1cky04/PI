#include <stdio.h>
#include <math.h>
#include <assert.h>


const char *author = ("Ricardo Aleluia");


int alpha3(const char *codigo, const char *nome)
{
	int u = 0;
	for(int i = 0; nome[i] != '\0'; i++)
	{
		if(nome[i] == codigo[u])
		{
			u++;
		}
	}
	return u;
}

void test(void)
{
	char codigo[3];
	char nome[1000];
	scanf("%s", codigo);
	while(scanf("%s", nome) != EOF)
	{
		int x = alpha3(codigo, nome);
		if(x >= 3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}


void unit_test_alpha3(void)
{
	assert(alpha3("ptg", "portugal") == 3);
	assert(alpha3("fra", "franca") == 3);
	assert(alpha3("lka", "sri lanka") == 3);
	assert(alpha3("dem", "alemanha") != 3);
	assert(alpha3("zbl", "brazil") != 3);
}

int main(void)
{
	unit_test_alpha3();
	test();
	return 0;
}