#include <stdio.h> 
// getchar() reads a character from the standard input and returns the value of the character read as an unsigned char converted to an int
// This program copies its input to its output one character at a time
int main(void){
    int c;
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}

// To compile the code, open the terminal and run the following command
// gcc copyInput.c -o copyInput.exe
// .\copyInput.exe