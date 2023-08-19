#include <stdio.h>
#include <string.h>

int main()
{
    char name[25];
    printf("Gimme Your Name:\n");

    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';

    while (strlen(name) == 0)
    {
        printf("Bro you did not enter your name!");
        printf("Gimme Your Name, I mean it!\n");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
    }

    printf("Hello %s\n", name);

    return 0;
}