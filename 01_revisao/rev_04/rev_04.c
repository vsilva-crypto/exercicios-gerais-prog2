#include <stdio.h>

typedef struct 
{
    int numIntDecimal;
    int restoDivisao[50];
    int tamanhoUsadoDoVetor;  
} intDecimal;

intDecimal leNumInteiroDecimal()
{
    intDecimal num;
    scanf ("%d", &num.numIntDecimal);
    return num;
}

intDecimal converteParaOctal(intDecimal num)
{
    int i = 0;

    while (num.numIntDecimal != 0)
    {
        num.restoDivisao[i] = num.numIntDecimal % 8;
        num.numIntDecimal = num.numIntDecimal / 8;
        i++;
    }

    num.tamanhoUsadoDoVetor = i;
    return num;
}

void imprimeResultado(intDecimal num)
{
    int i; 

    for (i = num.tamanhoUsadoDoVetor - 1; i >= 0; i--)
    {
        printf ("%d", num.restoDivisao[i]);
    }
}

int main ()
{
    intDecimal num;

    num = leNumInteiroDecimal();
    num = converteParaOctal(num);
    imprimeResultado(num);

    return 0;
}