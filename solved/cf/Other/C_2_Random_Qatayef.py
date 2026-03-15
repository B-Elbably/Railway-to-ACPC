def factorize(n) :
    if n < 2 :
        return set()
    factors = set()
    for i in range(2, int(n**0.5) + 1) :
        while n % i == 0 :
            factors.add(i)
            n //= i
    if n > 1 :
        factors.add(n)
    return factors

n = int(input());
a = list(map(int, input().split()));
a.sort()

used =  factorize(a[0])
used |= factorize(a[0] - 1)
used |= factorize(a[0] + 1)
used |= factorize(a[-1])
used |= factorize(a[-1] - 1)
used |= factorize(a[-1] + 1)

ans = 10**18
for p in used :
    res = 0
    for ai in a :
        if ai < p :
            step = p - ai
        else :
            step = min(ai % p, p - ai % p)
        res += step
        if res >= ans : break
    ans = min(ans, res);
    
print(ans)