@echo off
gcc  -Wall -Wextra -std=c99 -Ofast -flto -s c99.c -o c99
REM clang -Wall -Wextra -Ofast -std=c99 -flto -fuse-ld=lld c99.c -o c99clang.exe //run from vsprompt
REM cl /Wall /O2 /Fe"c99vs.exe" c99.c //run from vsprompt
rustc --edition 2021 -C opt-level=3 -C codegen-units=1 -C lto=true -C strip=symbols -C panic=abort rustlang.rs
go build -ldflags "-s -w" golang.go
hyperfine "c99 %~1" "rustlang %~1" "golang %~1" > bench.txt