package main

import "fmt"

func power(base, exp int) int {
	result := 1
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

func sum_of_proper_divisors(n int) int {
	sum_of_all_factors := 1
	n_mut := n
	step := 0
	for n_mut%2 == 0 {
		step += 1
		n_mut /= 2
	}
	sum_of_all_factors *= power(2, step+1) - 1
	for i := 3; i*i <= n_mut; i += 2 {
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
	sum := 0
	for i := 3; i < 10000; i++ {
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
