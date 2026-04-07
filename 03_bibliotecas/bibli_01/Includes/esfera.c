#include "esfera_utils.h"


float calcula_volume (float R)
{
    float Volume;
    Volume = (4 * PI * (R * R * R)) / 3.0;
    return Volume;
}

float calcula_area (float R)
{ 
    float area;
    area = 4 * PI * (R * R);
    return area;
}