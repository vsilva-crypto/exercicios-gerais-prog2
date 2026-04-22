#include <stdio.h>

int verificaBissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

}

int numeroDiasMes(int mes, int ano)
{
    switch(mes)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return verificaBissexto(ano) ? 29 : 28;
        default:
            return -1; 
    }
}

int verificaDataValida(int dia, int mes, int ano)
{
    if (ano < 1) return 0; 

    if (mes < 1 || mes > 12) return 0; 

    int diasNoMes = numeroDiasMes(mes, ano);
    if (diasNoMes == -1) return 0; 

    if (dia < 1 || dia > diasNoMes) return 0; 

    return 1;
}

void imprimeData(int dia, int mes, int ano)
{
    printf ("%02d/%02d/%04d", dia, mes, ano);
}

void imprimeMesExtenso(int mes)
{
    switch(mes)
    {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Março");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d", ano);
}


int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2) return 1;

    else if (ano1 < ano2) return -1;

    else
    {
        if (mes1 > mes2) return 1;

        else if (mes1 < mes2) return -1;

        else
        {
            if (dia1 > dia2) return 1;
            else if (dia1 < dia2) return -1;
            else return 0; 
        }
    }
}

int calculaDiasAteMes(int mes, int ano)
{
    int quantidadeDeDias = 0;
    int i;

    for (i = 1; i < mes; i++)
    {
        quantidadeDeDias += numeroDiasMes(i, ano);
    }

    return quantidadeDeDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias1 = dia1 + calculaDiasAteMes(mes1, ano1);
    int dias2 = dia2 + calculaDiasAteMes(mes2, ano2);

    int totalDias1 = dias1;
    int totalDias2 = dias2;

    for (int i = 1; i < ano1; i++)
    {
        totalDias1 += verificaBissexto(i) ? 366 : 365;
    }

    for (int i = 1; i < ano2; i++)
    {
        totalDias2 += verificaBissexto(i) ? 366 : 365;
    }

    int diferenca = totalDias2 - totalDias1;

    if (diferenca < 0)
        diferenca = -diferenca;

    return diferenca;
}

void imprimeProximaData(int dia, int mes, int ano)
{
    if (verificaDataValida(dia + 1, mes, ano))
    {
        imprimeData(dia + 1, mes, ano);        
        return;
    }

    if (verificaDataValida(1, mes + 1, ano))
    {
        imprimeData(1, mes + 1, ano);
        return;
    }

    if (verificaDataValida(1, 1, ano + 1))
    {
        imprimeData(1, 1, ano + 1);
        return;
    }
}