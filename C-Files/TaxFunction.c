#include <stdio.h>

void functionName(char arr[], int id); // prototype to ensure args are correct
int applyTax(int, float);
int main()
{
    // printf("%d", applyTax(550000, 0.3f));
    printf("Result: $%d\n", applyTax(65000, 0.3f)); // Woot 45,500
    return 0;
}

void functionName(char[], int id){

};

int applyTax(int basePay, float taxRate)
{
    return basePay - (basePay * taxRate);
}
