fn d(n: i32) -> i32 {
    (1..(n / 2 + 1)).
        filter(|m| n % m == 0).sum()
}

fn amicable(n:i32) -> i32 {
    let dn=d(n);
    let ddn=d(dn);
    if (ddn==n) && (n != dn) {
        n
    } else {
        0
    }
}

fn main () {
    let mut result:i32=0;
    for i in 1..10000 {
        result = result + amicable(i);
    }
    println!("{}", result);
}