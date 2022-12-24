#include <stdio.h>
#include <math.h>
#include <assert.h>


const char *author = ("Ricardo Aleluia");


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema A

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


void testA(void)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema B

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

void testB(void)
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


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema C

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

void testC(void)
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

void unit_test_subsequences(void)
{
	assert(lenght("abcd") == sequences("abcd", "abcde"));
	assert(lenght("ualg") == sequences("ualg", "universidade_do_algarve"));
	assert(lenght("lei") == sequences("lei", "licenciatura_em_engenharia_informatica"));
	assert(!(lenght("pt") == sequences("pt", "marrocos")));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problema D

int space_remover(const char *phrase, char *telegram, const char *space)
{
	int n = 0;
	for(int i = 0; phrase[i] != '\0'; i++)
	{
		if(phrase[i] != space[0])
		{
			telegram[n++] = phrase[i];
		}
	}
	telegram[n] = '\0';
	return n;
}

void testD(void)
{
	char phrase[1000] = {};
	char space[1] = {'_'};
	while(scanf("%s", phrase) != EOF)
	{
		char telegram[1000] = {};
		space_remover(phrase, telegram, space);
		printf("%s", telegram);
		printf("\n");
	}
}

void unit_test_space_remover(void)
{
	char space[1] = {'_'};
	char telegram1[1000] = {};
	assert(space_remover("_portugal_", telegram1, space) == 8);
	assert(space_remover("_ricardo_aleluia_", telegram1, space) == 14);
	assert(space_remover("__D__", telegram1, space) == 1);
	assert(space_remover("marry_christmas", telegram1, space) == 14);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  int x = 'A';
  if (argc > 1)
  {
	x = *argv[1];
  }
  if (x == 'A')
  {
  	unit_test_str_find();
  	unit_test_alpha2();
  	testA();
  }
  else if (x == 'B')
  {
  	unit_test_alpha3();
  	testB();
  }
  else if (x == 'C')
  {
  	unit_test_subsequences();
  	testC();
  }
  else if (x == 'D')
  {
  	unit_test_space_remover();
  	testD();
  }
  else if (x == 'E')
  {
  	printf("All unit tests PASSED.\n");
  }
  else
  {
  	printf("%s: Invalid option.\n", argv[1]);
  }
  return 0;
}