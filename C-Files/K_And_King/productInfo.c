#include <stdio.h>

int main(void){
    int itemNumber, month, day, year;
    float unitPrice;
    printf("Enter item number: ");
    scanf_s("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf_s("%f", &unitPrice);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf_s("%d/%d/%d", &month, &day, &year);
    printf("Item\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t$%7.2f\t%d/%d/%d\n", itemNumber, unitPrice, month, day, year);
    return 0;
}

// To compile the code, open the terminal and run the following command
// gcc productInfo.c -o productInfo.exe
// .\productInfo.exe