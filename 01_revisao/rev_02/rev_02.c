#include <stdio.h>

int leQuantidadeDeLinhas()
{
    int nLinhas;
    scanf ("%d", &nLinhas);
    return nLinhas;
}

void imprimeTrianguloDeFloyd(int nLinhas)
{
    int linha, coluna, numero = 1;

    for (linha = 1; linha <= nLinhas; linha++)
    {
        for (coluna = 0; coluna != linha; coluna++)
        {
            printf ("%d ", numero);
            numero++;
        }

        printf ("\n");
    }
}

int main ()
{
    int nLinhas;
    nLinhas = leQuantidadeDeLinhas();
    imprimeTrianguloDeFloyd(nLinhas);
    return 0;
}