#include <stdio.h>

int main(void)
{
    printf("This \ais an alert\a\n");
    int i, j;
    float x, y;
    scanf_s("%d %d %f %f", &i, &j, &x, &y);
    printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);
    return 0;
}

// To compile the code, open the terminal and run the following command
// gcc escapeSeq.c -o escapeSeq.exe
// .\escapeSeq.exe