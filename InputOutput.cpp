#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void BuferDelete()
{
        while(getchar()!='\n') {}
}

void Input(double *a, double *b, double *c)
{
    printf("Enter a, b, c coefficients as in ax^2 + bx + c \n");

    int input = (scanf("%lf %lf %lf", a, b, c)==3);;
    while(!input)
    {
        BuferDelete();
        printf("Enter error, try again\n");
        input = (scanf("%lf %lf %lf", a, b, c)==3);
    }
}

void Output(int nRoots, double x, double x1, double x2)
{
    assert(isfinite(nRoots));
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch (nRoots)
    {
        case 0: printf("no solutions");
                break;
        case 1: printf("x = %lf", x);
                break;
        case 2: printf("x1 = %lf, x2 = %lf", x1, x2);
                break;
        case -1: printf("infinite solutions");
                break;
        default: printf("unknown error");
                break;
    }
}
