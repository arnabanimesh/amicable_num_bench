@echo off
gcc  -Wall -Wextra -std=c99 -Ofast -flto -s c99.c -o c99
rustc --edition=2018 -O rsiter.rs
rustc --edition=2018 -O rsitersum.rs
rustc --edition=2018 -O rsloop.rs
go build -ldflags "-s -w" goloop.go
ghc -O2 -optl-s hsiter.hs
hyperfine -w 3 c99 rsiter rsitersum rsloop goloop hsiter
PAUSE