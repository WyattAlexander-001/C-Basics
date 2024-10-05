#include <stdio.h>

// print Fahrenheit-Celsius table
int main(void){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // lower limit of temperature table
    upper = 150; // upper limit of temperature table
    step = 1; // step size

    // fahr = lower;
    celsius = lower;
    // printf("Fahrenheit\tCelsius\n");
    printf("Celsius\tFahrenheit\n");
    while (fahr <= upper){
        // celsius = (5.0/9.0) * (fahr - 32.0);
        fahr = (9.0/5.0) * celsius + 32.0;
        // printf("%3.0f %6.1f\n", fahr, celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        // fahr = fahr + step;
        celsius = celsius + step;
    }
}

// To compile the code, open the terminal and run the following command
// gcc FtoCTable.c -o FtoCTable.exe
// .\FtoCTable.exe