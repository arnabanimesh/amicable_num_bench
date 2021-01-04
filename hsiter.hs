d :: Int -> Int
d n = foldl (\acc m -> if (mod n m)==0; then acc+m; else acc) 1 [2..(div n 2)]

amicable :: Int -> Int
amicable n = if ((d (d n)) == n) && (n /= (d n)); then n ; else 0
main = do print (foldl (\acc n -> acc + (amicable n)) 0 [1 .. 9999])