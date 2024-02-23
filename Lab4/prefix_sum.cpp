#include "prefix_sum.h"
#include <iostream>

int prefix_sum(int ary[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += ary[i];
    }
    return sum;
}

bool non_positive_prefix(int ary[], int length)
{
    int cumulativeSum = 0;

    for (int index = 0; index < length; index++)
    {
        cumulativeSum += ary[index];
        if (cumulativeSum > 0)
        {
            return false;
        }
    }

    return true;
}

bool non_negative_prefix(int ary[], int length)
{
    int cumulativeSum = 0;

    for (int index = 0; index < length; index++)
    {
        cumulativeSum += ary[index];
        if (cumulativeSum < 0)
        {
            return false;
        }
    }

    return true;
}
