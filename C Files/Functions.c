#include <stdio.h>

// Function For Printing
void happyBirthday(char name[], int age)
{
    printf("Happy Birthday %s! You are %d years old!\n", name, age);
}

// Function For Returning
double square(double x)
{
    return x * x;
}

double biggerNumber(double a, double b)
{
    return (a > b) ? a : b; // if a < b return a, otherwise b!
}

int main()
{
    char name[] = "Wyatt";
    int age = 21;

    happyBirthday(name, age);  // using variables
    happyBirthday("Anni", 27); // using values
    // happyBirthday();           // Will bork

    double num = square(4.453);
    printf("%50.4lf \n", num);
    printf("%50.3lf \n", num);
    printf("%50.2lf \n", num);

    double testBiggerNumber = biggerNumber(125, 777);
    printf("%0.lf\n", testBiggerNumber);

    return 0;
}