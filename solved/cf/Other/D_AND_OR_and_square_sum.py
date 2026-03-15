from collections import defaultdict, deque
n = int(input())
a = list(map(int, input().split()))
a.sort()

idx = defaultdict(deque)
for i in range(n):
    for j in range(21) :
        if (a[i] >> j) & 1:
            idx[j].append(i)
            
for i in range(n - 1, 0, -1) :
    for j in range(21) :
        if (a[i] >> j) & 1: continue
        if (not idx[j] or idx[j][0] >= i) : continue
        k = idx[j].popleft()
        a[i] += 1 << j
        a[k] -= 1 << j

ans = 0
for i in range(n) :
    ans += a[i] * a[i]
print(ans)