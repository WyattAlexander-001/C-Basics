#include <stdio.h>

int main(void){
    printf("Hello, World I GOT GCC INSTALLED ON WINDOWS 10!!!\n");
    printf("Here's an experiment with escape, \ttabbing1\bback\bspacing\n"); // \c is not a valid escape sequence so you will get an error
}


// To compile the code, open the terminal and run the following command
// gcc hello_world.c -o hello_world.exe
// .\hello_world.exe