#include <stdio.h>
#include <math.h>
#include <assert.h>


const char *author = ("Ricardo Aleluia");

int str_find2(const char *nome, int first, const char s)
{
	int result;
	for(int i = first + 1; nome[i] != '\0'; i++)
	{
		if(s == nome[i])
		{
			result = i;
			break;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

int str_find(const char *nome, const char s)
{
	int result;
	for(int i = 0; nome[i] != '\0'; i++)
	{
		if(s == nome[i])
		{
			result = i;
			break;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

int alpha2(const char *codigo, const char *nome)
{
	int result;
	int first = str_find(nome, codigo[0]);
	int second = str_find2(nome, first, codigo[1]);
	if(first != -1 && second != -1 && first != second)
	{
		result = 1;
	}
	else
		result = 0;
	return result;
}


void test(void)
{
	char codigo[1];
	scanf("%s",codigo);
	char nome[1000];
	while(scanf("%s", nome) != EOF)
	{
		int u = alpha2(codigo, nome);
		if(u == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}

void unit_test_str_find(void)
{
	assert(str_find("abcdedfghi", 'a') == 0); 
	assert(str_find("abcdedfghi", 'd') == 3);
	assert(str_find("abcdedfghi", 'g') == 7); 
	assert(str_find("abcdedfghi", 'i') == 9); 
	assert(str_find("abcdedfghi", 'p') == -1); 
	assert(str_find("", 'z') == -1);
}

void unit_test_alpha2(void)
{
	assert(alpha2("pt", "portugal"));
	assert(alpha2("fr", "franca"));
	assert(alpha2("lk", "sri lanka"));
	assert(!alpha2("de", "alemanha"));
	assert(!alpha2("zb", "brazil"));
}


int main(void)
{
	unit_test_str_find();
	unit_test_alpha2();
	test();
}