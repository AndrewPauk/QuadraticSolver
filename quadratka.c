#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Output(int nRoots, double x, double x1, double x2) {
    switch (nRoots) {
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

int isZero (double n) {
    double calc_error = 1e-8;
    return (fabs(n) < calc_error);
}

void BuferDelete() {
        while(getchar()!='\n') {}
}

void Input(double *a, double *b, double *c) {
    printf("Enter a, b, c coefficents as in ax^2 + bx + c \n");
    int input = (scanf("%lf %lf %lf", a, b, c)==3);;
    while(!input) {
        BuferDelete();
        printf("Enter error, try again\n");
        input = (scanf("%lf %lf %lf", a, b, c)==3);
        }
}

int SolveLinear(double b, double c, double *x) {
    if (isZero(b)) {
        if (isZero(c))
            return -1;
        else
            return 0;
    }
    else {
        if (isZero(c)) {
            *x=0;
            return 1;
        }
        else {
            *x = (-c)/b;
            return 1;
            }
    }
}

int SolveQuadratic(double a, double b, double c, double *x, double *x1, double *x2) {
    if (isZero(a)) {
        return SolveLinear(b, c, x);
    }
    else {
        if (isZero(b)) {
            if (isZero(c)) {
                *x=0;
                return 1;
            }
            else {
                if ((-c)/a < 0) {
                    return 0;
                }
                else {
                    *x1 = sqrt((-c)/a);
                    *x2 = (-1)*sqrt((-c)/a);
                    return 2;
                }
            }
        }
        else {
            if (isZero(c)) {
                *x1 = 0;
                *x2 =(-b)/a;
                return 2;
            }
            else {
                double discriminant;
                discriminant = sqrt(b*b - 4*a*c);
                if (discriminant>=0) {
                    if (isZero(discriminant)) {
                        *x = (-b)/(2*a);
                        return 1;
                    }
                    else {
                        *x1 = (-b + discriminant)/(2*a);
                        *x2 = (-b - discriminant)/(2*a);
                        return 2;
                    }
                }
                else {
                    return 0;
                    }
            }
        }
    }
}

void Test(int Test_Number, double a, double b, double c, int real_nRoots, double real_x, double real_x1, double real_x2)
{
    double test_x = 0, test_x1 = 0, test_x2 = 0;
    int test_nRoots = SolveQuadratic(a, b, c, &test_x, &test_x1, &test_x2);

    if ((test_nRoots != real_nRoots) || (!isZero(test_x - real_x)) || (!isZero(test_x1 - real_x1)) || (!isZero(test_x2 - real_x2)))
    {
        printf("\nFailed test #%d, expected number of roots = %d, test number of roots = %d ", Test_Number, real_nRoots, test_nRoots);

        printf("\nExpected: ");
        Output(real_nRoots, real_x, real_x1, real_x2);

        printf("\nResulted: ");
        Output(test_nRoots, test_x, test_x1, test_x2);
    }
    else
        printf("\nSuccessful test #%d", Test_Number);
}

void StartTests() {
//       N   a    b   c  nRoots x     x1  x2
    Test(1,  0,   0,  0,   -1,  0, 0,     0);
    Test(2,  0,   0,  1,    0,  0, 0,     0);
    Test(3,  0,   1,  0,    1,  0, 0,     0);
    Test(4,  0,   1,  1,    1, -1, 0,     0);
    Test(5,  1,   0,  0,    1,  0, 0,     0);
    Test(6,  1,   0,  1,    0,  0, 0,     0);
    Test(7,  1,   0, -1,    2,  0, 1,    -1);
    Test(8,  1,   1,  0,    2,  0, 0,    -1);
    Test(9,  1,   2,  3,    0,  0, 0,     0);
    Test(10, 1,   4,  4,    1, -2, 0,     0);
    Test(11, 1,  -5,  6,    2,  0, 3,     2);
    Test(12, 1, 2.5, -9,    2,  0, 2,  -4.5);
}

int main() {
    double a=0, b=0, c=0, x=0, x1=0, x2=0;
    Input(&a, &b, &c);
    int nRoots = SolveQuadratic(a, b, c, &x, &x1, &x2);
    Output(nRoots, x, x1, x2);
    StartTests();
}