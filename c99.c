//go:build ignore
#include <stdio.h>
#include <stdint.h>

int32_t power(int32_t base, int32_t exp)
{
    int32_t result = 1;
    for (;;)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        exp /= 2;
        if (exp == 0)
        {
            break;
        }
        base *= base;
    }
    return result;
}

int32_t sum_of_proper_divisors(int32_t n)
{
    int32_t sum_divisors = 1;
    int32_t n_mut = n;
    int32_t step = 0;
    while (n_mut % 2 == 0)
    {
        step += 1;
        n_mut /= 2;
    }
    sum_divisors *= power(2, step + 1) - 1;
    int32_t i = 3;
    while (i * i <= n_mut)
    {
        step = 0;
        while (n_mut % i == 0)
        {
            step += 1;
            n_mut /= i;
        }
        sum_divisors *= (power(i, step + 1) - 1) / (i - 1);
        i += 2;
    }
    if (n_mut > 2)
    {
        sum_divisors *= (n_mut * n_mut - 1) / (n_mut - 1);
    }
    return sum_divisors - n;
}

int32_t main()
{
    int32_t amicable_sum = 0;
    for (int32_t i = 3; i < 10000; i++)
    {
        int32_t s = sum_of_proper_divisors(i);
        if (s == i)
        {
            continue;
        }
        if (sum_of_proper_divisors(s) == i)
        {
            amicable_sum += i;
        }
    }
    printf("%d\n", amicable_sum);
    return 0;
}