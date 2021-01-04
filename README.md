# [Problem: #21 Amicable Numbers Benchmark using C, Go, Haskell and Rust](https://projecteuler.net/problem=21)

## Description:

This is a benchmark between `C`, `Go`, `Haskell`, and `Rust`. `Rust` allows for different forms of implementation using `stdlib` so there are multiple implementations.

Source codes were taken from [this thread](https://users.rust-lang.org/t/executable-size-and-performance-vs-c/4496).

> It is just a hobby project to perform benchmark.

## Contribution guidelines:

1. If you want to suggest flaws with this benchmark, you can open issues.
2. If you want to change algorithm, you have to change the algorithm in all the languages.

### Notes:

1. Here the focus is on similar algorithm rather than the most efficient one
2. C compilation params: `gcc -Wall -Wextra -std=c99 -Ofast -flto -s c99.c -o c99`
3. the rust exe with no suffix was built with `-O` only
4. Go compilation command: `go build -ldflags "-s -w" goloop.go`
5. `-ldflags "-s -w"` removes debug symbols.
6. Haskell was built with `ghc -O2 -optl-s hsiter.hs`
7. `bench.txt` is the output after running `run.cmd`
