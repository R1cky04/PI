#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");


double expression(double l, double v)
{
	return l != v ? (( l / v ) + 1+(0.25*(v-l))/10) : 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}

double out2(double excesso, double l, double v)
{
	double multa = expression(l,v);
	if(excesso <= 80)
	{
		multa *= 300;
		return min(multa ,1500);
	}
	else
	{
		multa *= 500;
		return min(multa ,2500);		
	}
}

double out(double l,double v)
{
	double excesso = v-l;
	double multa = expression(l,v);
	if(excesso <= 30)
	{
		multa *= 60;
		return min(multa ,300);
	}
	else if(excesso <= 60)
	{
		multa *= 120;
		return min(multa ,600);
	}
	else
		return out2(excesso, l, v);
}

double in2(double excesso, double l, double v)
{
	double multa = expression(l,v);
	if(excesso <= 60)
	{
		multa *= 300;
		return min(multa ,1500);
	}
	else
	{
		multa *= 500;
		return min(multa ,2500);		
	}
}

double in(double l,double v)
{
	double excesso = v - l;
	double multa = expression(l,v);
	if(excesso <= 20)
	{
		multa *= 60;
		return min(multa ,300);
	}
	else if(excesso <= 40)
	{
		multa *= 120;
		return min(multa ,600);
	}
	else
		return in2(excesso,l,v);
}

double place(double l, double v, int s)
{
	if(s == 0)
	{
		return printf("%.2f\n", in(l,v));
	}
	else
	{
		return printf("%.2f\n", out(l,v));
	}
}

void test(void)
{
	double l, v;
	int s;
	while(scanf("%lf%lf%d",&l ,&v ,&s) != EOF) // l=limite de velocidade , v=velocidade atingida , s=dentro ou fora de localidade
	{
		place(l, v, s);
	}
}

int main(void)
{
	test();
	return 0;
}