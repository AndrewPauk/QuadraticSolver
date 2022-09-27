#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define EPS 1e-11

void sort2(double *a, double *b)
{
    if (*a > *b)
    {
        double temp = 0;

        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int isZero (double n)
{
    return (fabs(n) < EPS);
}

int SolveLinear(double b, double c, double *x)
{
    assert(x != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (isZero(b))
    {
        if (isZero(c))
            return -1;
        else
            return 0;
    }
    else
    {
        if (isZero(c))
        {
            *x=0;
            return 1;
        }
        else
        {
            *x = (-c)/b;
            return 1;
        }
    }
}

int SolveQuadratic(double a, double b, double c, double *x, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);
    assert(x  != NULL);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if ((isZero(a) || isZero(b) || isZero(c))  && isfinite(b/a) && isfinite(c/a))
    {
        b = b/a;
        c = c/a;
        a = 1;
    }

    if (isZero(a))
        return SolveLinear(b, c, x);
    else
    {
        if (isZero(b))
        {
            if (isZero(c))
            {
                *x=0;
                return 1;
            }
            else
            {
                if ((-c)/a < 0)
                    return 0;
                else
                {
                    *x1 = (-1)*sqrt((-c)/a);
                    *x2 = sqrt((-c)/a);
                    return 2;
                }
            }
        }
        else
        {
            if (isZero(c))
            {
                *x1 = 0;
                *x2 =(-b)/a;
                sort2(x1, x2);
                return 2;
            }
            else
            {
                double discriminant;
                discriminant = sqrt(b*b - 4*a*c);
                if (discriminant>=0)
                {
                    if (isZero(discriminant))
                    {
                        *x = (-b)/(2*a);
                        return 1;
                    }
                    else
                    {
                        *x1 = (-b + discriminant)/(2*a);
                        *x2 = (-b - discriminant)/(2*a);
                        sort2(x1, x2);
                        return 2;
                    }
                }
                else
                    return 0;
            }
        }
    }
}
