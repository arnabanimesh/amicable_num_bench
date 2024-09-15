package main

import (
	"fmt"
	"os"
	"strconv"
)

func power(base uint64, exp uint32) uint64 {
	var result uint64 = 1
	for {
		if exp%2 == 1 {
			result *= base
		}
		exp /= 2
		if exp == 0 {
			break
		}
		base *= base
	}
	return result
}

func sum_of_proper_divisors(n uint64) uint64 {
	var sum_of_all_factors uint64 = 1
	var n_mut uint64 = n
	var step uint32 = 0
	for n_mut%2 == 0 {
		step += 1
		n_mut /= 2
	}
	sum_of_all_factors *= power(2, step+1) - 1
	var i uint64
	for i = 3; i*i <= n_mut; i += 2 {
		step = 0
		for n_mut%i == 0 {
			step += 1
			n_mut /= i
		}
		sum_of_all_factors *= (power(i, step+1) - 1) / (i - 1)
	}
	if n_mut > 2 {
		sum_of_all_factors *= (n_mut*n_mut - 1) / (n_mut - 1)
	}
	return sum_of_all_factors - n
}

func main() {
	var max_limit uint64 = 10000
	if len(os.Args) > 1 {
		var err error
		max_limit, err = strconv.ParseUint(os.Args[1], 10, 64)
		if err != nil {
			panic("Enter a valid integer as first CLI argument or pass no argument to consider a max limit of 10,000")
		}
	}
	var sum uint64 = 0
	var i uint64
	for i = 3; i < max_limit; i++ {
		s := sum_of_proper_divisors(i)
		if s == i {
			continue
		}
		if sum_of_proper_divisors(s) == i {
			sum += i
		}
	}
	fmt.Println(sum)
}
