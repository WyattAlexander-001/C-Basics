#include <stdio.h>
#include <math.h>

int main(void)
{
    float loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment;
    int numberOfPayments;

    printf("Enter the amount of the loan: ");
    scanf_s("%f", &loanAmount);

    printf("Enter the annual interest rate (in percent): ");
    scanf_s("%f", &annualInterestRate);    

    printf("Enter the number of payments: ");
    scanf_s("%d", &numberOfPayments);

    // Convert annual interest rate to monthly decimal rate
    monthlyInterestRate = annualInterestRate / 12 / 100;

    // Calculate the monthly payment using the correct formula
    monthlyPayment = (loanAmount * monthlyInterestRate) / 
                     (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

    printf("The monthly payment is: $%.2f\n", monthlyPayment);

    return 0;
}


// To compile the code, open the terminal and run the following command
// gcc paymentPlanCalculator.c -o paymentPlanCalculator.exe
// .\paymentPlanCalculator.exe