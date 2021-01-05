#!/usr/bin/luajit

function d(n)
    local result = 1
    for m = 2,n/2+1 do 
        if n % m == 0 then
            result = result + m
        end
    end
    return result
end

function amicable(n)
    local dn = d(n);
    local ddn = d(dn);
    local result = 0
    if ddn == n and n ~= dn and n < 100000 then
        result = result + n
    end
    return result
end

function main()
    local result = 0
    for i = 1,10000 do
        result = result + amicable(i)
    end
    print(result)
    return 0
end

main()
