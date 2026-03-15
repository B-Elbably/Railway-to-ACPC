from decimal import Decimal, getcontext
getcontext().prec = 50

def solve():
    n, q = map(int, input().split())
    ls = list(map(Decimal, input().split()))
    mp = {}
    for i in range(n):
        ls[i] *= Decimal(3).sqrt() / Decimal(2)
        ls[i] = f"{ls[i]:.6f}"
        mp[ls[i]] = i + 1

    for _ in range(q):
        a, b, c = map(Decimal, input().split())
        a = a.sqrt()
        b = b.sqrt()
        c = c.sqrt()
        d = a + b + c
        d = f"{d:.6f}"
        if d in mp:
            print(mp[d])
        else:
            print(-1)

solve()