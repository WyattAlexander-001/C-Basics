#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: \n");
    scanf("%d", &age);

    if (age == 21)
    {
        printf("You're allowed into the bar, first time huh?\n");
    }
    else if (age > 21 && age < 65)
    {
        printf("Hi grandpa!\n");
    }
    else
    {
        printf("Get out\n");
    }

    char grade;
    printf("Enter your letter grade (A-F): ");
    scanf(" %c", &grade); // The space before %c ensures any previous newline or whitespace is ignored

    switch (grade)
    {
    case 'A':
        printf("A, you did perfect!\n");
        break;
    case 'B':
        printf("B, good job!\n");
        break;
    case 'C':
        printf("C, you did okay.\n");
        break;
    case 'D':
        printf("D, just above failing.\n");
        break;
    case 'F':
        printf("F, you failed!\n");
        break;
    default:
        printf("Invalid grade. Please enter a letter between A and  in UPPERCASE.\n");
    }
    return 0;
}