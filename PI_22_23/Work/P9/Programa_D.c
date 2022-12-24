#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = ("Ricardo Aleluia");

int array_max(int *a, int counter)
{
    int max = a[0];
    for(int i = 0; i < counter; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int ints_argsmax(int *a, int counter, int *b)
{
    int n = 1;
    int times = 0;
    for(int i = 0; i < counter; i++)
    {
        if(a[i] == array_max(a, counter))
        {
            b[n++] = i;
            times++;
        }
    }
    b[0] = times;
    return times;
}

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

void test(void)
{
    int a[1000] = {};
    int b[1000] = {};
    int counter = ints_get(a);
    printf("%d", ints_argsmax(a, counter, b));
    for(int i = 1; i <= ints_argsmax(a, counter, b); i++)
    {
        printf(" %d", b[i]);
    }
    printf("\n");
}

void asserts(void)
{
    int a1[3] = {6,2,6};
    int b1[1000];
    ints_argsmax(a1,3,b1);
    assert(b1[0] == 2);
    assert(b1[1] == 0);
    assert(b1[2] == 2);
    int a2[4] = {2,3,7,7};
    int b2[1000];
    ints_argsmax(a2,4,b2);
    assert(b2[0] == 2);
    assert(b2[1] == 2);
    assert(b2[2] == 3);
    int a3[5] = {7,9,6,9,9};
    int b3[1000];
    ints_argsmax(a3,5,b3);
    assert(b3[0] == 3);
    assert(b3[1] == 1);
    assert(b3[2] == 3);
    assert(b3[3] == 4);
    int a4[6] = {3,4,4,4,5,4};
    int b4[1000];
    ints_argsmax(a4,6,b4);
    assert(b4[0] == 1);
    assert(b4[1] == 4);
}

int main(void)
{
    asserts();
    test();
    return 0;
}