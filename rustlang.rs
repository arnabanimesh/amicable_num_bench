fn sum_of_proper_divisors(n: u32) -> u32 {
    let mut sum_divisors = 1;
    let mut n_mut = n;
    let mut step = 0;
    while n_mut % 2 == 0 {
        step += 1;
        n_mut /= 2;
    }
    sum_divisors *= 2_u32.pow(step + 1) - 1;
    let mut i = 3;
    while i * i <= n_mut {
        step = 0;
        while n_mut % i == 0 {
            step += 1;
            n_mut /= i;
        }
        sum_divisors *= (i.pow(step + 1) - 1) / (i - 1);
        i += 2;
    }
    if n_mut > 2 {
        sum_divisors *= (n_mut * n_mut - 1) / (n_mut - 1);
    }
    sum_divisors - n
}

fn main() {
    let mut amicable_sum = 0;
    for i in 3..10000 {
        let s: u32 = sum_of_proper_divisors(i);
        if s == i {
            continue;
        }
        if sum_of_proper_divisors(s) == i {
            amicable_sum += i;
        }
    }
    println!("{}", amicable_sum);
}
