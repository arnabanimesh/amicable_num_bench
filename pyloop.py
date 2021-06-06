#!/usr/bin/pypy3

def d(n):
    result = 1;
    for m in range(2, int(n / 2 + 1)):
        if (n % m) == 0:
            result += m
    return result

def amicable(n):
    dn=d(n)
    ddn=d(dn)
    if (ddn==n) and (n != dn):
        return n
    else:
        return 0

def main():
    result=0
    for i in range(1, 10000):
        result += amicable(i);
    print(result)

if __name__ == '__main__':
    main()
