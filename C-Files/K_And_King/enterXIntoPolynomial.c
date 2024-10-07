#include <stdio.h>

// Function prototype
void printPolynomial(int num);

int main(void) {
    int num;
    printf("Enter a number for X for the given polynomial: ");
    scanf_s("%d", &num); // scanf_s is a secure version of scanf; the & is used to get the address of the variable num
    printPolynomial(num);
}

// Function to make formatting the output easier
void printPolynomial(int num) {
    printf("The value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 is: %d\n", 3*num*num*num*num*num + 2*num*num*num*num - 5*num*num*num - num*num + 7*num - 6);
}

// To compile the code, open the terminal and run the following command
// gcc enterXIntoPolynomial.c -o enterXIntoPolynomial.exe
// .\enterXIntoPolynomial.exe