// This program shows examples of Break, Continue, and Goto statements in C
// Break - The break statement is used to exit the loop or switch statement in which it appears
// Continue - The continue statement is used to skip the rest of the code inside a loop for the current iteration only
// Goto - The goto statement is used to transfer control to a different part of the program

#include <stdio.h>

int main(void)
{

    // Break statement
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            printf("Break statement at, i = %d\n", i);
            break;
        }
        printf("i = %d\n", i);
    }

    printf("\n");

    // Continue statement
    for (i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            printf("Continue statement at, i = %d\n", i);
            continue;
        }
        printf("i = %d\n", i);
    }

    printf("\n");

    // Goto statement
    begin:; //This will cause an infinite loop
    for (i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            printf("Goto statement at, i = %d\n", i);
            goto end;
        }
        printf("i = %d\n", i);
    }
    end:
    printf("End of program we jumped at, i = %d\n", i);
    goto begin;
    return 0;
}

// To compile the code, open the terminal and run the following command
// gcc breakContinueGoto.c -o breakContinueGoto.exe
// .\breakContinueGoto.exe