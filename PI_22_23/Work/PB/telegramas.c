#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = ("Ricardo Aleluia");


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

void test(void)
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

int main(int argc, char **argv)
{
  int x = 'D';
  if (argc > 1)
  {
		x = *argv[1];
  }
  if (x == 'D')
  {
  	unit_test_space_remover();
  	test();
  }
  else if (x == 'B')
  {
  	printf("All unit tests PASSED.\n");
  }
  else
  {
  	printf("%s: Invalid option.\n", argv[1]);
  }
  return 0;
}