#include <stdio.h>

int main()
{
    // while loop = checks a condition, THEN executes a block of code if condition is true
    // do while loop = always executes a block of code once, THEN checks a condition

    int number = 0;
    int sum = 0;

    do // do it once then check condition, cool.
    {
        printf("Enter a # above 0:\n");
        scanf("%d", &number);
        if (number > 0)
        {
            sum += number;
        }
    } while (number > 0);

    printf("Your sum: %d\n", sum);

    return 0;
}