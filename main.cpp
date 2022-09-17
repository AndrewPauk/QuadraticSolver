#include <stdio.h>

#include "InputOutput.cpp"
#include "QuadraticSolver.cpp"
#include "Tests.cpp"
#include "header.h"

int main()
{
    double a = 0, b = 0, c = 0, x = 0, x1 = 0, x2 = 0;
    Input(&a, &b, &c);

    int nRoots = SolveQuadratic(a, b, c, &x, &x1, &x2);
    Output(nRoots, x, x1, x2);

    StartTests();
}
