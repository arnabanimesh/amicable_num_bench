fn d(n: i32) -> i32 {
    (1..(n / 2 + 1)).
        filter(|m| n % m == 0).sum()
}

fn main () {
    let result: i32 = (0..10000).reduce(|sum,n| {let dn=d(n);
        if (d(dn)==n) && (n != dn) {sum+n} else {sum}}).unwrap();
    println!("{}", result);
}