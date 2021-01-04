package main

import (
	"fmt"
)

func d(n int) int {
	result := 1
	for m := 2; m < n/2+1; m = m + 1 {
		if n%m == 0 {
			result += m
		}
	}
	return result
}

func amicable(n int) int {
	dn := d(n)
	ddn := d(dn)
	if ddn == n && n != dn {
		return n
	} else {
		return 0
	}
}

func main() {
	result := 0
	for i := 0; i < 10000; i = i + 1 {
		result = result + amicable(i)
	}
	fmt.Println(result)
}
