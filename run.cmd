@echo off
gcc  -Wall -Wextra -std=c99 -Ofast -flto -s c99.c -o c99
REM clang -Wall -Wextra -Ofast -std=c99 -flto -fuse-ld=lld c99.c -o c99clang.exe //run from vsprompt
REM cl /Wall /O2 /Fe"c99vs.exe" c99.c //run from vsprompt
rustc --edition=2018 -O -Ctarget-cpu=native rsiter.rs
rustc --edition=2018 -O -Ctarget-cpu=native rsitersum.rs
rustc --edition=2018 -O -Ctarget-cpu=native rsloop.rs
go build -ldflags "-s -w" goloop.go
ghc -O2 -optl-s hsiter.hs
hyperfine -w 3 c99 c99clang c99vs rsiter rsitersum rsloop goloop hsiter
PAUSE