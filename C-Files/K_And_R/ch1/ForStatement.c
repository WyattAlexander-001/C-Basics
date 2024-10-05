#include <stdio.h>

int main(void){
    int num;
    printf("Enter a number: ");
    scanf_s("%d", &num); // scanf_s is a secure version of scanf the & is used to get the address of the variable numn
    for (int i = 0; i < num; i++){
        printf("You are on iteration %d of %d\n", i, num);
    }
}

// To compile the code, open the terminal and run the following command
// gcc ForStatement.c -o ForStatement.exe
// .\ForStatement.exe
/*
Example Output:
Enter a number: 10
You are on iteration 0 of 10
You are on iteration 1 of 10
You are on iteration 2 of 10
You are on iteration 3 of 10
You are on iteration 4 of 10
You are on iteration 5 of 10
You are on iteration 6 of 10
You are on iteration 7 of 10
You are on iteration 8 of 10
You are on iteration 9 of 10
*/