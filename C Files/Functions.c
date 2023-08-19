#include <stdio.h>

void happyBirthday(char name[], int age)
{
    printf("Happy Birthday %s! You are %d years old!\n", name, age);
}

int main()
{
    char name[] = "Wyatt";
    int age = 21;

    happyBirthday(name, age);  // using variables
    happyBirthday("Anni", 27); // using values
    // happyBirthday();           // Will bork
    return 0;
}