#include <stdio.h>
#include "data.h"

int main ()
{
    int dia, mes, ano;
    int quantidadeDias;
    scanf ("%02d/%02d/%04d", &dia, &mes, &ano);

    if (verificaDataValida(dia, mes, ano))
    {
        printf ("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);
        printf ("\n");

        if (verificaBissexto(ano))
            printf("O ano informado eh bissexto\n");

        else
            printf ("O ano informado nao eh bissexto\n");

        quantidadeDias = numeroDiasMes(mes, ano);
        printf ("O mes informado possui %02d dias\n", quantidadeDias);

        printf ("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
        printf ("\n");
    }

    else 
        printf ("A data informada eh invalida\n");

    return 0;
}