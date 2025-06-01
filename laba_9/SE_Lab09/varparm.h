#include <iostream>

namespace Varparm
{
    int ivarparm(int n, ...)
    {
        int* args = &n;
        int prod = 1;
        for (int i = 0; i < n; i++)
        {
            args += 2;
            prod *= *args;
        }
        return prod;
    }

    int svarparm(short n, ...) 
    {
        short* args = &n;
        short maxVal = *(args + 4);
        for (int i = 0; i < n; i++)
        {
            args += 4;
            if (*args > maxVal)
            {
                maxVal = *args;
            }
        }
        return maxVal;
    }

     double fvarparm(float n, ...)
     {
        double sum = n;
        double* args = (double*)(&n+2);
        float* args1 = (&n + 2);
        for (int i = 2; *(double*)args1 != FLT_MAX; i++)
        {
            sum += *args;
            args = (double*)(&n + 2 * i);
            args1 += 2;
        }
        return sum;
    }

    double dvarparm(double n, ...) {
        double sum = 0;
        double* args = &n;
        for (int i = 0; *(args + i) != DBL_MAX; i++)
        {
            sum += *(args + i);
        }
        return sum;
    }
}