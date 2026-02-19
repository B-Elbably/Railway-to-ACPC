MOD = 998244353

def modexp(x, n):
    x %= MOD
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % MOD
        x = (x * x) % MOD
        n >>= 1
    return res

def MulMat(a, b):
    n, m, k = len(a), len(b), len(b[0])
    ans = [[0] * k for _ in range(n)]
    for i in range(n):
        for j in range(k):
            for l in range(m):
                ans[i][j] = (ans[i][j] + a[i][l] * b[l][j] % MOD) % MOD
    return ans

def MatPower(Matrix, p):
    sz = len(Matrix)
    ans = [[0] * sz for _ in range(sz)]
    for i in range(sz):
        ans[i][i] = 1
    base = [row[:] for row in Matrix]
    while p:
        if p & 1:
            ans = MulMat(ans, base)
        base = MulMat(base, base)
        p >>= 1
    return ans

n, q = map(int, input().split())
a = [int(input()) for _ in range(n)]

Matrix = [[-2, 1], [0, (n - 2) % MOD]]
Matrix = MatPower(Matrix, q)

sm = (sum(a) * Matrix[0][1]) % MOD

for i in range(n):
    a[i] = (a[i] * Matrix[0][0] % MOD + sm) % MOD
    print(a[i])
