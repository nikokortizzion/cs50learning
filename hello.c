# include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name;
    name = get_string("Wat is your name?\n");
    printf("Hello, %s\n", name);
}
