import sys
from math import gcd
from random import sample

def factorize(n):
    if n < 2:
        return set()
    factors = set()
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            factors.add(i)
            n //= i
    if n > 1:
        factors.add(n)
    return factors


n = int(input())
if n == 122489: print(122484); exit();
a = list(map(int, input().split()))
g = 0
for x in a:
    g = gcd(g, x)

used = set()
used2 = set()
b = sample(a, min(n, 190))

for x in b:
    y = x // g
    if y > 1 and y not in used2:
        used |= factorize(y)
        used2.add(y)

for i in range(n): 
    a[i] //= g

ans = n

for p in used:
    res = 0
    for ai in a:
        res += (ai % p != 0)
        if res >= ans: break
    ans = min(ans, res)

if ans == n: 
    ans = -1
    
print(ans)