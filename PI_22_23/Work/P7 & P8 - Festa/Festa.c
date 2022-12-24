30 - // progressão aritmética
43 - //arrendondar para cima, às décimas
51 - //retorna o valor maior dos dois argumentos
59 - //calcula a soma em binÃ¡rio
67 - //calcula o produto entre x e y
75 - //calcula a soma entre x e y
83 - //fatorial de um número inteiro n
104 - //contar os termos de uma soma aproximada
131 - // torna um numero par
139 - //  calcular o máximo divisor comum de dois números inteiros
166 - // cálculo do comprimento de um número inteiro
187 - // mostra cada digito de um número da direita para a esquerda
219 - // função para percorrer um número da direita para a esquerda
230 - // função para calcular se o número é capicua ou não
238 - // função que conta os números inteiros positivos
249 - // contagem dos números inteiros positivos mais o zero(números naturais)
259 - // função igual à primeira só que com arrays 
270 - // caso geral da função digits_positive
284 - //função que escreve os valores de todos os elementos na mesma linha, antecedidos por um espaço
295 - // função que digite um array com os elementos de outro array, por ordem inversa
303 - // função que lê da consola uma sequencia de números até ao fim dos dados(EOF). Cada numero lido é acrescentado ao array
324 - // função que conta quantos elementos do array têm o valor dado
346 - // função que calcula a soma de arrays
354 - // função que a partir da soma dos arrays calcula a sua média





// progressão aritmética
double sum_progression(double x, double r, int n)
{
	double result = 0.0;
	for (int i = 0; i < n; i++)
	{
		result += x;
		x += r;
	}
	return result;



//arrendondar para cima, às décimas
double arredondada_decimal(double x)
{
  return ceil(x * 10.0) / 10.0; 
}



//retorna o valor maior dos dois argumentos
double nota_requerida(double pratica, double alvo)
{
  return fmax(8.5, nota_requerida_precisa(pratica,alvo));
}



//calcula a soma em binÃ¡rio
int sum_binary(int x,int y)
{
	return y == 0 ? x : 2*(sum_binary(x/2, y/2) + (x%2 && y%2)) + (x%2 ^ y%2); 
}



//calcula o produto entre x e y
int product(int x,int y)
{
	return y==0 ? 0 : sum(x,product(x,y-1));
}



//calcula a soma entre x e y
int sum(int x, int y)
{
	return y==0 ? x : sum(x+1,y-1);
}



//fatorial de um número inteiro n
double fatorial(int n)
{
	double result = 1.0;
	for (int i = 0; i < n; i++)
		result *= i + 1;
	return result;
}

void teste_f(void)
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		double z = fatorial(x);
		printf("%g\n", z);
	}
}



//contar os termos de uma soma aproximada
int count_terms(double x, double limit, double epsilon)
{
	int result = 0;
	double sum = 0.0;
	double term = 1.0;
	while (sum <= limit - epsilon)
	{
		result++;
		sum += term;
		term *= x;
	}
	return result;
}

void test_count_terms(void)
{
	double epsilon;
	while(scanf("%lf", &epsilon) != EOF)
	{
		int z1 = count_terms(0.5,2.0,epsilon);
		printf("%d\n", z1);
	}
}



// torna um numero par
int collatz(int x)
{
	return x % 2 == 0 ? x / 2 : 3 * x + 1;
}



//  calcular o máximo divisor comum de dois números inteiros
int gcd(int x,int y)
{
	while(x != y)
	{
		if(x > y)
			x-=y;
		else
			y -= x;
	}
	return x;
}

void teste_euclid(void)
{
	int x,y;
	while(scanf("%d%d", &x,&y) != EOF)
	{
		int z1 = euclid(x,y);
		printf("%d\n", z1);
		int z2 = gcd(x,y);
		printf("%d\n", z2);
	}
}



// cálculo do comprimento de um número inteiro
int decimal_lenght_i(int x)
{
	int result = 1;
	while(x >= 10)
	{
		result++;
		x/= 10;
	}
	return result;
}

void test_decimal_length(void)
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		int z1 = decimal_lenght_i(x);
		printf("%d\n", z1);
	}
}
// mostra cada digito de um número da direita para a esquerda
void show_digits(int x)
{
	while(x >= 10)
	{
		printf("%d ", x % 10);
		x /= 10;	
	}
	printf("%d", x);
}

void show_digits_left_to_right(int x)
{
	while(x < 10)
	{
		printf("%d ", x % 10);
		x / 10;	
	}
	printf("%d", x);
}

void test_show_digits_both_ways(void)
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		show_digits(x);
		printf("\n");
		show_digits_left_to_right(x);
		printf("\n");
	}
}
// função para percorrer um número da direita para a esquerda
int reverse(int x)
{
	int result = 0;
	while (x > 0)
	{
		result = 10 * result + x % 10;
		x /= 10;
	}
	return result;
}
// função para calcular se o número é capicua ou não
int is_palindrome(int x)
{
	return x == reverse(x);
}



// função que conta os números inteiros positivos
int count_digits_positive(int x)
{
	int result = 0;
	while(x > 0)
	{
		result++;
		x /= 10;
	}
	return result;
}
// contagem dos números inteiros positivos mais o zero(números naturais)
int count_digits(int x)
{
	int result = 1;
	if(x > 0)
	{
		result = count_digits_positive(x);
	}
	return result;
}
// função igual à primeira só que com arrays 
int digits_positive(int x, int *a)
{
	int result = 0;
	while(x > 0)
	{
		a[result++] = x % 10;
		x /= 10;
	}
	return result;
}
// caso geral da função digits_positive
int digits(int x, int *a)
{
	int result = 1;
	a[0] = 0;
	if(x > 0)
		result = digits_positive(x, a);
	return result;
}





//função que escreve os valores de todos os elementos na mesma linha, antecedidos por um espaço
void ints_println_basic(const int *a, int n)
{
	if(n > 0)
	{	
		printf("%d", a[0]);
		for (int i = 0; i < n; i++)
			printf(" %d", a[i]);
	}
	printf("\n");
}
// função que digite um array com os elementos de outro array, por ordem inversa
int mirror(const int *a, int n, int *b)
{
	int result = 0;
	for(int i = n-1; i >= 0; i--)
		b[result++] = a[i];
	return result;
}
// função que lê da consola uma sequencia de números até ao fim dos dados(EOF). Cada numero lido é acrescentado ao array
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

test: int n = ints_get(a)




double double_get(double *a)
{
	int result = 0;
	double x;
	while(scanf("%d", &x) != EOF)
		a[result++] = x;
	return result;
}
// função que conta quantos elementos do array têm o valor dado
double doubles_count(const double *a, int n, double x)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
			result++;
	}
	return result;
}
void doubles_println_basic(const double *a, int n)
{
	if(n > 0)
	{	
		printf("%d", a[0]);
		for (int i = 0; i < n; i++)
			printf(" %g", a[i]);
	}
	printf("\n");
}

// função que calcula a soma de arrays
double doubles_sum(const double *a, int n)
{
	double result = 0;
	for(int i = 0; i < n; i++)
		result += a[i];
	return result;
}
// função que a partir da soma dos arrays calcula a sua média
double doubles_mean(const double *a, int n)
{
	return doubles_sum(a,n) / n;
}


#include <math.h>
sin(x)
cos(x)
tan(x)
asin(x) = arc sin
acos(x) = arc cos
atan2(y, x) = arc tan de y/x
exp(x) Exponencial de x
log(x) logaritmo de x
pow(x, y) potencia de x elevado a y
sqrt(x) raiz quadrada de x
floor(x) maior numero inteiro menor ou igual a x
ceil(x) menor numero inteiro ou igual a x
round(x) numero inteiro mais proximo de x
fabs(x) valor absoluto de x
