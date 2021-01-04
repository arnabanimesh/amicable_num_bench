fn d(n: i32) -> i32 {
    (2..(n / 2 + 1)).
        filter(|m| n % m == 0).
        fold(1, |result, i| result + i)
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