#include <stdio.h>

#define Name "Wyatt B"
#define Age 30
#define PI 3.14159

int main(void){
    printf("Hello, my name is %s and I am %d years old.\n", Name, Age);
    // Name = "John Doe"; // This will give you an error because you cannot change the value of a constant
    printf("Hello, my name is %s and I am %d years old.\n", Name, Age);
    printf("The value of PI is %f\n", PI);
    printf("The value of PI is %.2f\n", PI);
    printf("The value of PI is %.3f\n", PI);
    printf("The value of PI is %.4f\n", PI);
    printf("The value of PI is %.5f\n", PI);
    printf("The value of PI is %.6f\n", PI);
    printf("The value of PI is %.7f\n", PI);
    printf("The value of PI is %.8f\n", PI);
    printf("The value of PI is %.9f\n", PI);
    printf("The value of PI is %.10f\n", PI);
    printf("The value of PI is %.11f\n", PI);
    printf("The value of PI is %.12f\n", PI);
    printf("The value of PI is %.13f\n", PI);
    printf("The value of PI is %.14f\n", PI);
    printf("The value of PI is %.15f\n", PI);
    printf("The value of PI is %.16f\n", PI);
    printf("The value of PI is %.17f\n", PI);
    printf("The value of PI is %.18f\n", PI);
    printf("The value of PI is %.19f\n", PI);
    printf("The value of PI is %.20f\n", PI);
    printf("The value of PI is %.21f\n", PI);
    printf("The value of PI is %.22f\n", PI);
    printf("The value of PI is %.23f\n", PI);
    printf("The value of PI is %.24f\n", PI);
    printf("The value of PI is %.25f\n", PI);
    printf("The value of PI is %.26f\n", PI);
    printf("The value of PI is %.27f\n", PI);
    printf("The value of PI is %.28f\n", PI);
    printf("The value of PI is %.29f\n", PI);
    printf("The value of PI is %.30f\n", PI);
    printf("The value of PI is %.31f\n", PI);
    printf("The value of PI is %.32f\n", PI); // The value .32f will output 3.14158999999999988261834005243145 because of floating point precision
}

// To compile the code, open the terminal and run the following command
// gcc defineConstant.c -o defineConstant.exe
// .\defineConstant.exe