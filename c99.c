#include <stdio.h>
#include <stdint.h>

int32_t d(const int32_t n) {
    int32_t result = 1;
    for (int32_t m = 2; m < n / 2 + 1; m++) {
        if ((n % m) == 0) {
            result += m;
        }
    }
    return result;
}

int32_t amicable(const int32_t n) {
    const int32_t dn = d(n);
    const int32_t ddn = d(dn);
    int32_t result = 0;
    if (ddn == n && n != dn && n < 100000) {
        result += n;
    }
    return result;
}

int main() {
    int32_t result = 0;
    for (int32_t i = 1; i < 10000; i++) {
        result += amicable(i);
    }
    printf("%d\n", result);
    return 0;
}