#include <stdio.h>
#include <math.h>

typedef struct 
{
    float posX, posY;
    float raio;
} tAlvo;

typedef struct 
{
    float posX, posY;
    float raio;
} tMira;

tAlvo leValoresDoAlvo()
{
    tAlvo valoresAlvo;
    scanf ("%f %f %f", &valoresAlvo.posX, &valoresAlvo.posY, &valoresAlvo.raio);
    return valoresAlvo;
}

tMira leValoresDaMira()
{
    tMira valoresMira;
    scanf ("%f %f %f", &valoresMira.posX, &valoresMira.posY, &valoresMira.raio);
    return valoresMira;
}

int verificaSeAlvoFoiAcertado(tAlvo valoresAlvo, tMira valoresMira)
{
    float distancia;
    
    distancia = sqrt(pow(valoresAlvo.posX - valoresMira.posX, 2) + pow(valoresAlvo.posY - valoresMira.posY, 2));

    return distancia <= (valoresAlvo.raio + valoresMira.raio);
}

int main ()
{
    tAlvo valoresAlvo;
    tMira valoresMira;
    int Verificador;

    valoresAlvo = leValoresDoAlvo();
    valoresMira = leValoresDaMira();
    Verificador = verificaSeAlvoFoiAcertado(valoresAlvo, valoresMira);

    if (Verificador) printf ("ACERTOU");
    else printf ("ERROU");

    return 0;
}