#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");


double bi_hourly(double consumos_mensais_dia, double consumos_mensais_noite)
{
	double despesa_total = 0;
	despesa_total = (((consumos_mensais_dia * 0.26120) + (consumos_mensais_noite * 0.20620)) * 1.25) + 18.551;
	return despesa_total * 1.23;
}

double simple(double consumos_mensais_dia, double consumos_mensais_noite)
{
	double despesa_total = 0;
	despesa_total = (((consumos_mensais_dia + consumos_mensais_noite) * 0.23770) * 1.25) + 15.903;
	return despesa_total * 1.23;
}

void test(void)
{
	double consumos_mensais_dia;
	double consumos_mensais_noite;
	while(scanf("%lf%lf", &consumos_mensais_dia, &consumos_mensais_noite) != EOF)
	{
		printf("%0.2f %0.2f\n", simple(consumos_mensais_dia, consumos_mensais_noite), bi_hourly(consumos_mensais_dia, consumos_mensais_noite));
	}
}

int main(void)
{
	test();
	return 0;
}