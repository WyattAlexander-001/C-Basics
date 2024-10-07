#include <stdio.h>

int main(void){
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf_s("%d/%d/%d", &month, &day, &year);
    printf("You entered the date (%d/%d/%d)\n", month, day, year);
    return 0;
}

// To compile the code, open the terminal and run the following command
// gcc dateInput.c -o dateInput.exe
// .\dateInput.exe