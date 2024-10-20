#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int r;

    printf("Insert radius: ");
    scanf_s("%d", &r);

    int d = 2*r;

    do {
        for (int x=0; x<=d; ++x) {
            for (int y=0; y<=d; ++y) {
                for (int z=0; z<=d; ++z) {
                    if (sqrt(pow(x-r, 2) + pow(y-r, 2) + pow(r-z, 2)) < r)
                        printf(".");      // using single-spacing
                    else
                        printf(" ");
                }
                puts("");
            }
            system("cls");
        }
    } while(time(NULL));
}

// To compile the code, open the terminal and run the following command
// gcc circleLoop.c -o circleLoop.exe
// .\circleLoop.exe