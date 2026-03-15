from bisect import bisect_right
n, q = map(int, input().split())
a = list(map(int, input().split()))

pref = [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] + a[i]

for _ in range(q):
    x = int(input())
    ans = bisect_right(pref, x)
    if ans > n:
        print(-1)
    else:
        print(ans)

