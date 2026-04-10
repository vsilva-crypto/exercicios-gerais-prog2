#include <stdio.h>
#include "esfera_utils.h"

int main ()
{
    float raio, volume, area;
    scanf ("%f", &raio);

    area = calcula_area(raio);
    volume = calcula_volume(raio);

    printf ("AREA: %.2f\n", area);
    printf ("VOLUME: %.2f", volume);

    return 0;
}

