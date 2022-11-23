#include <math.h>
#include <stdio.h>

int main()
{
    double angle = 1.2*M_PI;
    double rayX = cos(angle);
    double rayY = sin(angle);
    printf("%f %f\n", rayX, rayY);
    return(0);
}