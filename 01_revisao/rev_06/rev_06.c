#include <stdio.h>
#define TAM_MAX_LISTA 1001

typedef struct 
{
    int quantidadeLimite;
    char listaRotulos[TAM_MAX_LISTA];
} tEstoque;

tEstoque leQuantidadeDeLimites()
{
    tEstoque limite;
    scanf ("%d", &limite.quantidadeLimite);
    return limite;
}

tEstoque leListaDeRotulos(tEstoque estoque)
{
    scanf ("%s", estoque.listaRotulos);
    return estoque;
}

void imprimeFunkosEmPromocao(int rotulo, int quantidade)
{
    printf ("%c: %d", (char)rotulo, quantidade);
}

void verificaQuaisCategoriasEntramEmPromocao(tEstoque estoque)
{
    int i, j, quantidade, achou = 0; 

    for (i = 48; i < 123; i++)
    {
        quantidade = 0;

        for (j = 0; estoque.listaRotulos[j] != '\0'; j++)
        {
            if (estoque.listaRotulos[j] == i)
                quantidade++;
        }

        if (quantidade > estoque.quantidadeLimite)
        {
            imprimeFunkosEmPromocao(i, quantidade);
            printf ("\n");
            achou = 1;
        }
    }

    if (!achou) 
        printf ("NENHUM");
}

int main ()
{
    tEstoque estoque;
    estoque = leQuantidadeDeLimites();
    estoque = leListaDeRotulos(estoque);
    verificaQuaisCategoriasEntramEmPromocao(estoque);
    return 0;
}