#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string names[] = {"Carter", "David"};
    string numbers[] = {"08222222222", "08333333333"};

    string name = get_string("Name : ");
    for (int i=0 ; i< 2 ;i++)
    {
        if(strcmp(names[i],name) == 0 ){
            printf ("Found %s\n",numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
