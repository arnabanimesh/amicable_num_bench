// go:build ignore
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>

bool strtouint64_safe(const char *str, uint64_t *val)
{
    char *temp;
    errno = 0;
    bool rc = true;
    *val = (uint64_t)strtol(str, &temp, 0);
    if (temp == str || *temp != '\0' || (((*val == (uint64_t)LONG_MIN) || (*val == (uint64_t)LONG_MAX)) && (errno == ERANGE)))
        rc = false;
    return rc;
}

uint64_t power(uint64_t base, uint32_t exp)
{
    uint64_t result = 1;
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

uint64_t sum_of_proper_divisors(uint64_t n)
{
    uint64_t sum_divisors = 1;
    uint64_t n_mut = n;
    uint32_t step = 0;
    while (n_mut % 2 == 0)
    {
        step += 1;
        n_mut /= 2;
    }
    sum_divisors *= power(2, step + 1) - 1;
    uint64_t i = 3;
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

int32_t main(int32_t argc, char **argv)
{
    uint64_t max_limit = 10000;
    if (argc > 1)
    {
        if (strtouint64_safe(argv[1], &max_limit) == false)
        {
            fprintf(stderr, "Enter a valid integer as first CLI argument or pass no argument to consider a max limit of 10,000");
            exit(1);
        }
    }
    uint64_t amicable_sum = 0;
    for (uint64_t i = 3; i < max_limit; i++)
    {
        uint64_t s = sum_of_proper_divisors(i);
        if (s == i)
        {
            continue;
        }
        if (sum_of_proper_divisors(s) == i)
        {
            amicable_sum += i;
        }
    }
    printf("%" PRIu64 "\n", amicable_sum);
    return 0;
}