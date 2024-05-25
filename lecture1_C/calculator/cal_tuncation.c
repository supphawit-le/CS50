#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x = ");
    long y = get_long("y = ");

    //type caster
    float z = (float) x / (float) y;
    //double  = float x 2
    printf ("%f\n", z);
}
