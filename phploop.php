#!/usr/bin/php
<?php
function d($n) {
    $result = 1;
    for ($m = 2; $m < $n/2+1; $m++) {
        if ($n % $m == 0) {
            $result += $m;
        }
    }
    return $result;
}

function amicable($n) {
    $dn = d($n);
    $ddn = d($dn);
    $result = 0;
    if ($ddn == $n && $n != $dn && $n < 100000) {
        $result += $n;
    }
    return $result;
}

function main() {
    $result = 0;
    for ($i = 1; $i < 10000; $i++) {
        $result += amicable($i);
    }
    print($result);
}

main()
?>
