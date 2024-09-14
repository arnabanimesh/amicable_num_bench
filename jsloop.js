#!/usr/bin/nodejs

"use strict"

function d(n) {
    var result = 1;
    for (var m = 2; m < n / 2 + 1; m++) {
        if ((n % m) == 0) {
            result += m;
        }
    }
    return result;
}

function amicable(n) {
    var dn = d(n);
    var ddn = d(dn);
    var result = 0;
    if (ddn == n && n != dn && n < 100000) {
        result += n;
    }
    return result;
}

function main() {
    var result = 0;
    for (var i = 1; i < 10000; i++) {
        result += amicable(i);
    }
    console.log(result);
}

main()
