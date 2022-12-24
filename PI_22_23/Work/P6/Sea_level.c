#include <stdio.h>
#include <math.h>
const char *author = ("Ricardo Aleluia");

int numero_de_anos(int altura_total)
{
    int anos = 0;
    double aumento = 0.400;
    double altura = 0;
    for (anos = 0; altura_total > altura; anos++)
    {
        if (anos % 8 == 0)
        {
            aumento = aumento + aumento*0.25;
        }
        altura = altura + aumento;
    }
    return anos;    
}


void test(void)
{
    int altura_total;    
    int result;
    while(scanf("%d", &altura_total) != EOF)
    {
        result = numero_de_anos(altura_total);
        printf("%d\n", result);
    }
}

int main(void)
{
    test();
    return 0;
}