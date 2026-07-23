import sys
input = sys.stdin.readline


mod = int(1e9) + 7
def solve():
    n = int(input())
    # x = pow(n , 3 , mod) - pow(max(0, n - 2), 3, mod)
    # y = pow(24 , x % mod , mod)
    # print(y)
    if (n == 1) :
        print(24)
        return
    x = pow(24, 8, mod);
    x *= pow(24, 12 * (n - 2), mod) 
    x %= mod;
    x *= pow(6, 6 * pow(n-2, 2, mod - 1), mod)
    x %= mod
    print(x)
    
for _ in range(int(input())):
    solve()