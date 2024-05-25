#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s,t;
    s = "Hello";
    t = "BYE!";
    for (int i =0; i<20;i++)
    {
        printf ("%i\t%p\n",s[i],(void*)&s[i]);
    }
    printf("%i\n",(12*16));
}
