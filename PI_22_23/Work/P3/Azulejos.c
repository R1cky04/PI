#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");



int blue_square(int comprimento, int altura)
{
	int azuis_quadrado = 1;
	int k = (altura/2 - 1);
	double z = ceil(altura/2);
	if (altura % 2 == 0) 
	{
		while(k != 0)
		{
			azuis_quadrado = azuis_quadrado + (1 + 4*k);
			--k;
		}
	}
	else if(altura % 2 != 0) 
	{
		while(z != 0)
		{
			azuis_quadrado = azuis_quadrado + (1 + 4*z);
			--z;
		}
	}
	return azuis_quadrado;
}



int blue_columns2(int comprimento, int altura)
{
	int azuis_colunas = 0;
	int c = (comprimento - altura);
	if(comprimento % 2 != 0 && altura % 2 == 0 && c == 1) // impar par n=1
	{
		azuis_colunas = floor(c/2+1) * altura;
	}
	else if(comprimento % 2 != 0 && altura % 2 == 0 && c != 1) // impar par n!=1
	{
		azuis_colunas = ceil(c/2+1) * altura; // impar impar / par par
	}
	else
	{
		azuis_colunas = c/2 * altura;
	}
	return azuis_colunas;
}



int blue_columns(int comprimento, int altura)
{
	int azuis_colunas = 0;
	int c = (comprimento - altura);
	if(comprimento % 2 == 0 && altura % 2 != 0 && c == 1) // par impar n=1
	{
		azuis_colunas = floor(c/2) * altura;	
	}
	else if(comprimento % 2 == 0 && altura % 2 != 0 && c != 1) // par impar n!=1
	{
		azuis_colunas = ceil(c/2) * altura;
	}
	else 
	{
		azuis_colunas = blue_columns2(comprimento, altura);
	}
	
	return azuis_colunas;
}




int yellow (int comprimento, int altura)
{

	return comprimento*altura - (blue_square(comprimento, altura) + blue_columns(comprimento, altura));

}




void teste(void)
{
	int comprimento;
	int altura;
	while(scanf("%d%d", &comprimento, &altura) != EOF)
	{
		int result1 = blue_square(comprimento, altura) + blue_columns(comprimento, altura);
		int result2 = yellow(comprimento, altura);
		printf("%d %d\n",result1, result2);
	}
}




int main(void)
{
	teste();
	return 0;
}