fn d(n: i32) -> i32 {
    (1..(n / 2 + 1)).
        reduce(|result, i| {if n%i==0 {result + i}else {result}}).unwrap_or_default()
}

fn main () {
    let result:i32=(0..10000).reduce(|sum, n| {let dn=d(n);
        if (d(dn)==n) && (n != dn) {sum+n} else {sum}}).unwrap();
    println!("{}", result);
}