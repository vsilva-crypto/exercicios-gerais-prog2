#include <stdio.h>

#define TAM_MAX_MATRIZ 100
#define QTD_MOVIMENTACAO 4

typedef struct 
{
    int linhas;
    int colunas;
    int mapa[TAM_MAX_MATRIZ][TAM_MAX_MATRIZ];
} tMapa;

typedef struct 
{
    int posJogadorX, posJogadorY; 
    int Xf, Yf; 
} tPosicao;

typedef struct 
{
    char movimentacao[QTD_MOVIMENTACAO];
} tMovimentacao;

tMapa leTamanhoDoMapa()
{
    tMapa infoMapa;
    scanf("%d %d", &infoMapa.linhas, &infoMapa.colunas);
    return infoMapa;
}

tMapa leDadosDoMapa(tMapa infoMapa)
{
    int i, j;

    for (i = 0; i < infoMapa.linhas; i++)
    {
        for (j = 0; j < infoMapa.colunas; j++)
        {
            scanf ("%d", &infoMapa.mapa[i][j]);
        }
    }

    return infoMapa;
}

tPosicao lePosicoes()
{
    tPosicao infoPosicao;
    scanf ("%d %d", &infoPosicao.posJogadorY, &infoPosicao.posJogadorX);
    scanf ("%d %d", &infoPosicao.Yf, &infoPosicao.Xf);
    
    infoPosicao.posJogadorY += -1;
    infoPosicao.posJogadorX += -1;
    infoPosicao.Xf += -1;
    infoPosicao.Yf += -1;

    return infoPosicao;
}

tMovimentacao lePrioridadeDeMovimentacao()
{
    tMovimentacao infoMovimentacao;
    int i;

    for (i = 0; i < QTD_MOVIMENTACAO; i++)
    {
        scanf (" %c", &infoMovimentacao.movimentacao[i]);
    }

    return infoMovimentacao;
}

void movePersonagem(tMapa mapa, tPosicao posicao, tMovimentacao movimentos)
{
    int chegouAoFim = 0, andou, conseguiuAndar;
    int i;
    
    printf("(%d,%d) ", posicao.posJogadorY + 1, posicao.posJogadorX + 1);

    if (posicao.posJogadorY == posicao.Yf && posicao.posJogadorX == posicao.Xf) return;

    while (!chegouAoFim)
    {
        conseguiuAndar = 0;

        for (i = 0; i < QTD_MOVIMENTACAO; i++)
        {
            andou = 0;

            if ((movimentos.movimentacao[i] == 'c' || movimentos.movimentacao[i] == 'C') && posicao.posJogadorY > 0 &&
                mapa.mapa[posicao.posJogadorY - 1][posicao.posJogadorX] == 0)
            {
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX] = -1;
                posicao.posJogadorY--;
                andou = 1;             
            }

            else if ((movimentos.movimentacao[i] == 'b' || movimentos.movimentacao[i] == 'B') && posicao.posJogadorY < mapa.linhas - 1 &&
                mapa.mapa[posicao.posJogadorY + 1][posicao.posJogadorX] == 0)
            {
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX] = -1;
                posicao.posJogadorY++;
                andou = 1;

            }

            else if ((movimentos.movimentacao[i] == 'd' || movimentos.movimentacao[i] == 'D') && posicao.posJogadorX < mapa.colunas - 1 &&
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX + 1] == 0)
            {
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX] = -1;
                posicao.posJogadorX++;
                andou = 1;
            }

            else if ((movimentos.movimentacao[i] == 'e' || movimentos.movimentacao[i] == 'E') && posicao.posJogadorX > 0 &&
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX - 1] == 0)
            {
                mapa.mapa[posicao.posJogadorY][posicao.posJogadorX] = -1;
                posicao.posJogadorX--;
                andou = 1;

            }

            if (andou == 1) 
            {
                printf("(%d,%d) ", posicao.posJogadorY + 1, posicao.posJogadorX + 1);
                conseguiuAndar = 1;
                if (posicao.posJogadorY == posicao.Yf && posicao.posJogadorX == posicao.Xf) chegouAoFim = 1;
                break;
            }
        }

        if (!conseguiuAndar) break;
    }

}

int main ()
{
    tMapa mapa;
    tMovimentacao movimentos;
    tPosicao posicao;

    mapa = leTamanhoDoMapa();
    mapa = leDadosDoMapa(mapa);

    posicao = lePosicoes();

    movimentos = lePrioridadeDeMovimentacao();

    movePersonagem(mapa, posicao, movimentos);

    return 0;
}