#include <stdio.h>
#include <stdlib.h>

void Test(int Test_Number, double a, double b, double c, int real_nRoots, double real_x, double real_x1, double real_x2)
{
    double test_x = 0, test_x1 = 0, test_x2 = 0;
    int test_nRoots = SolveQuadratic(a, b, c, &test_x, &test_x1, &test_x2);
    sort2(&test_x1, &test_x2);

    if ((test_nRoots != real_nRoots) || (!isZero(test_x - real_x)) || (!isZero(test_x1 - real_x1)) || (!isZero(test_x2 - real_x2)))
    {
        if ((test_nRoots == -1) && (real_nRoots == -1))
            printf("\nFailed test #%d, expected number of roots = infinite, test number of roots = infinite ", Test_Number);
        if ((test_nRoots == -1) && (real_nRoots != -1))
            printf("\nFailed test #%d, expected number of roots = infinite, test number of roots = %d ", Test_Number, test_nRoots);
        if ((test_nRoots != -1) && (real_nRoots == -1))
            printf("\nFailed test #%d, expected number of roots = %d, test number of roots = infinite ", Test_Number, real_nRoots);

        printf("\nFailed test #%d, expected number of roots = %d, test number of roots = %d ", Test_Number, real_nRoots, test_nRoots);

        printf("\nExpected: ");
        Output(real_nRoots, real_x, real_x1, real_x2);

        printf("\nResulted: ");
        Output(test_nRoots, test_x, test_x1, test_x2);
    }
    else
        printf("\nSuccessful test #%d", Test_Number);
}

void StartTests()
{
//       N   a    b   c  nRoots x     x1  x2
    Test(1,  0,   0,  0,   -1,  0,    0,  0);
    Test(2,  0,   0,  1,    0,  0,    0,  0);
    Test(3,  0,   1,  0,    1,  0,    0,  0);
    Test(4,  0,   1,  1,    1, -1,    0,  0);
    Test(5,  1,   0,  0,    1,  0,    0,  0);
    Test(6,  1,   0,  1,    0,  0,    0,  0);
    Test(7,  1,   0, -1,    2,  0,   -1,  1);
    Test(8,  1,   1,  0,    2,  0,   -1,  0);
    Test(9,  1,   2,  3,    0,  0,    0,  0);
    Test(10, 1,   4,  4,    1, -2,    0,  0);
    Test(11, 1,  -5,  6,    2,  0,    2,  3);
    Test(12, 1, 2.5, -9,    2,  0, -4.5,  2);
}
