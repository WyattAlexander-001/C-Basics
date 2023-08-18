#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*^^ You Need This by Default ^^ */
int main()
{
    printf("HELLO WORLD!\n");          // This is a comment
    printf("I like Pikmin 4!\n\n");    // \n new line
    printf("\t\tI like Persona 4!\n"); // \t tab!
    printf("0\tX\t0\tX\t0\tX\t0\tX\t\n");
    printf("Here is how you can \"QUOTE\" somthing\n");

    // Variables need to be declared like in Java
    int luckyNumber = 7;  // declare and the initialization
    int age = 29;         // %d for digit
    float gpa = 3.8;      // 32bits of precision %f for float
    double pi = 3.141592; // 64bits of precision %lf for 'long float'
    char grade = 'B';     // %c for char Use single quotes
    char name[] = "Jim";  // %s for stringWe need to make an aray of char to make STRINGS

    printf("Hi %s, your grade on the last test was %c \n", name, grade);
    printf("You are %d years old, your gpa is: %f \n", age, gpa);
    printf("Pi not PIE is: %lf \n", pi);

    bool lightSwitch = false;            //%d for digit 0=false 1=true
    unsigned char x = 120;               // 120 is x in ASCII we also get range of 0-255, don't get beyond 255
    printf("120 in ASCII is: %c \n", x); // Proof120 is x

    // We don't typically use unsigned long long int, but we get access to quintillion values!

    float apple = 1.996;
    float ipad = 639.99;
    float ipadCase = 35.98;
    printf("An apple costs: $%f \n", apple);      // not formatted
    printf("An apple costs: $%.2f \n", apple);    // formatted to 2 decimal
    printf("An apple costs: $%10.2f \n", apple);  // add 10 white space right aligned
    printf("An apple costs: $%-10.2f \n", apple); // subtract 10 white space, does nothing

    const float e = 2.71828; // constant variable, cannot be reassigned
    // Operators: +, -, *, /, % , ++, -- , -=, *=, +=, /=
    int divisionWithInt = 5 / 2;
    printf("%d \n", divisionWithInt); // truncates, 2.5 becomes 2

    // User Input:
    /*
        int dragonballs;
    printf("What is the number of Dragonballs?\n ");
    scanf("%d", &dragonballs); // scan needs to use &
    printf("You entered: %d, there is actually: 7 dragonballs \n", dragonballs);
    */
    char faveGame[25]; // 25 bytes
    printf("Tell me your favorite game \n");
    fgets(faveGame, 25, stdin);
    name[strlen(faveGame) - 1] = '\0';
    printf("Wow, you actually like, %s? \n", faveGame);

    return 0;
}