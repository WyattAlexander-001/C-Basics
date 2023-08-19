#include <stdio.h>
/*
Structure of C code:
function prototype
main function
functions


*/
void greet(char[], int id); // prototype to ensure args are correct

int main()
{
    greet("Jon", 44);
    greet("Tim");
    return 0;
}

void greet(char name[], int id)
{
    printf("Hello %s. You are Employee #%d\n", name, id);
};