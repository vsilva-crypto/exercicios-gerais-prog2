#include <stdio.h>

int informaQuantidadaDeLivros()
{
    int nLivros;
    scanf ("%d", &nLivros);
    return nLivros;
}

void leListaDeLivros(int lista[], int nLivros)
{
    int i;
    for (i = 0; i < nLivros; i++)
    {
        scanf ("%d", &lista[i]);
    }
}

void informaLivrosQuePrecisamDeCopias(int lista[], int nLivros)
{
    int i, j, qtdLivros, lidos, jaVerificado, achou = 0;
    
    for (i = 0; i < nLivros; i++)
    {
        qtdLivros = 0;
        jaVerificado = 0;

        for (lidos = 0; lidos < i; lidos++)
        {
            if (lista[lidos] == lista[i]) 
            {
                jaVerificado = 1;
                break;
            }
        }

        if (jaVerificado) continue;
        
        for (j = 0; j < nLivros; j++)
        {
            if (lista[j] == lista[i])
            {
                qtdLivros++;
            }
        }
        
        if (qtdLivros == 1) 
        {
            printf ("%d ", lista[i]);
            achou = 1;   
        }
    }

    if (!achou) printf ("NENHUM");
}

int main()
{
    int nLivros;
    nLivros = informaQuantidadaDeLivros();
    
    int lista[nLivros];
    leListaDeLivros(lista, nLivros);
    
    informaLivrosQuePrecisamDeCopias(lista, nLivros);
    return 0;
}