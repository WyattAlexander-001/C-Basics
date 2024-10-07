#include <stdio.h>

int main(void)
{
    float dollarAmount;
    printf("Enter a dollar amount: ");
    scanf_s("%f", &dollarAmount);
    printf("You entered $%.2f\n", dollarAmount);

    // Break down the dollar amount into bills and coins
    printf("$20 bills: %d\n", (int)(dollarAmount / 20));
    dollarAmount -= 20 * (int)(dollarAmount / 20); //Example with $100 it would be - 20 * 5 = 100
    printf("$10 bills: %d\n", (int)(dollarAmount / 10));
    dollarAmount -= 10 * (int)(dollarAmount / 10);
    printf("$5 bills: %d\n", (int)(dollarAmount / 5));
    dollarAmount -= 5 * (int)(dollarAmount / 5);
    printf("$1 bills: %d\n", (int)(dollarAmount / 1));
    dollarAmount -= 1 * (int)(dollarAmount / 1);
    printf("Quarters: %d\n", (int)(dollarAmount / 0.25));
    dollarAmount -= 0.25 * (int)(dollarAmount / 0.25);
    printf("Dimes: %d\n", (int)(dollarAmount / 0.10));
    dollarAmount -= 0.10 * (int)(dollarAmount / 0.10);
    printf("Nickels: %d\n", (int)(dollarAmount / 0.05));
    dollarAmount -= 0.05 * (int)(dollarAmount / 0.05);
    printf("Pennies: %d\n", (int)(dollarAmount / 0.01));
    return 0;
}

// To compile the code, open the terminal and run the following command
// gcc dollarBreakDown.c -o dollarBreakDown.exe
// .\dollarBreakDown.exe