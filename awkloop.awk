#!/usr/bin/mawk -f

# Warning: all variables are global in AWK
function d(nn) {
    d_result = 1
    for (m = 2; m < nn / 2 + 1; m++) {
        if ((nn % m) == 0) {
            d_result += m
        }
    }
    return d_result
}

function amicable(n) {
    dn = d(n)
    ddn = d(dn)
    ami_result = 0;
    if (ddn == n && n != dn && n < 100000) {
        ami_result += n
    }
    return ami_result
}

function main() {
    main_result = 0
    for (i = 1; i < 10000; i++) {
        main_result += amicable(i)
    }
    printf("%d\n", main_result)
}

BEGIN {
    main()
}
