#include <stdio.h>

int main()
{
    // 2 rows and 3 COLUMNS
    int numbers[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int luckyNumber = numbers[2][0]; // gets 7

    printf("%d\n", luckyNumber);
    return 0;
}