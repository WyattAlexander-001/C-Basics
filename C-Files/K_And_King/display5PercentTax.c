#include "stdio.h"

int main(void){
    float dollarAmount, tax;
    printf("Enter an amount: ");
    scanf_s("%f", &dollarAmount);
    tax = dollarAmount * 0.05;
    printf("With tax added: $%.2f\n", dollarAmount + tax);
    return 0;
}
// To compile the code, open the terminal and run the following command
// gcc display5PercentTax.c -o display5PercentTax.exe
// .\display5PercentTax.exe