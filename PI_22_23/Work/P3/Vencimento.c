#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

double vencimento(double salario, int horas, int minutos)
{
	double vencimento = 0;
	if(horas <= 13)
	{
		vencimento = (horas*60 + minutos - 9*60) * (salario/60 + salario/60*0.5);
	}
	else if (horas >= 14)
	{
		vencimento = (4*60*(salario/60 + salario/60*0.5)) + 6.5 + (horas*60 + minutos - 14*60) * (salario/60 + salario/60*0.75);
	}
	return round(vencimento*100)/100;
}

void teste(void)
{
	double salario;
	int horas;
	int minutos;
	while(scanf("%lf%d%d", &salario, &horas, &minutos) != EOF)
	{
		  double result = vencimento(salario, horas, minutos);
		  printf("%.6f\n", result);
	}
}

int main(void)
{
	teste();
	return 0;
} 