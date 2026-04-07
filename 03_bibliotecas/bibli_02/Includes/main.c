#include <stdio.h>
#include "matrix_utils.h"

void imprimeMenu()
{
    printf ("1 - Somar Matrizes\n");
    printf ("2 - Subtrair Matrizes\n");
    printf ("3 - Multiplicar Matrizes\n");
    printf ("4 - Multiplicacao de matriz por escalar\n");
    printf ("5 - Transposta de uma matriz\n");
    printf ("6 - Encerrar o programa\n");
    printf ("Opcao escolhida: ");
}

void interageComMenuDeOpcoes(int linhas1, int linhas2, int colunas1, int colunas2,
    int matriz1[linhas1][colunas1], int matriz2[linhas2][colunas2])
{
    int escolha = 0 ;
    int matrizFinal[linhas1][colunas1];
    int matrizFinalMultiplicacao[linhas1][colunas2];
    int escalar, escolhaMatriz, ehPossivel;

    while (escolha != 6)
    {
        imprimeMenu();
        scanf ("%d", &escolha);
        printf ("\n");

        if (escolha == 1)
        {
            ehPossivel = possible_matrix_sum(linhas1, colunas1, linhas2, colunas2);
            if (!ehPossivel)
            {
                printf ("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }

            matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinal);
            
            matrix_print(linhas1, colunas1, matrizFinal);
        }

        else if (escolha == 2)
        {
            ehPossivel = possible_matrix_sum(linhas1, colunas1, linhas2, colunas2);
            if (!ehPossivel)
            {
                printf ("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }

            matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinal);
                        
            matrix_print(linhas1, colunas1, matrizFinal);

        }

        else if (escolha == 3)
        {
            ehPossivel = possible_matrix_multiply(colunas1, linhas2);
            if (!ehPossivel)
            {
                printf ("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                continue;
            }

            matrix_multiply(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinalMultiplicacao);
    
            matrix_print(linhas1, colunas2, matrizFinalMultiplicacao);

        }

        else if (escolha == 4)
        {
            scanf ("%d", &escalar);
            scanf ("%d", &escolhaMatriz);

            if (escolhaMatriz == 1)
            {
                scalar_multiply(linhas1, colunas1, matriz1, escalar);

                matrix_print(linhas1, colunas1, matriz1);
            }
            
            else if (escolhaMatriz == 2)
            {
                scalar_multiply(linhas2, colunas2, matriz2, escalar);

                matrix_print(linhas2, colunas2, matriz2);
            }
        }

        else if (escolha == 5)
        {
            transpose_matrix(linhas1, colunas1, matriz1, matrizFinal);
            matrix_print(colunas1, linhas1, matrizFinal); 
            
            printf ("\n");
            
            transpose_matrix(linhas2, colunas2, matriz2, matrizFinal);  
            matrix_print(colunas2, linhas2, matrizFinal);
        }

        printf ("\n");
    }
}

int main ()
{
    int linhas1, linhas2, colunas1, colunas2;
    scanf ("%d %d", &linhas1, &colunas1);

    int matriz1[linhas1][colunas1];
    matrix_read(linhas1, colunas1, matriz1);

    scanf ("%d %d", &linhas2, &colunas2);

    int matriz2[linhas2][colunas2];
    matrix_read(linhas2, colunas2, matriz2);

    interageComMenuDeOpcoes(linhas1, linhas2, colunas1, colunas2,
        matriz1, matriz2);

    return 0;
}