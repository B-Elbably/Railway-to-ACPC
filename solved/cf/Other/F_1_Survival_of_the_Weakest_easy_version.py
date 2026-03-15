from heapq import heappush, heappop
MOD = 10**9 + 7

def calc(a):
    n = len(a)
    a.sort()
    res = []
    pq = []
    
    for i in range(n - 1):
        heappush(pq, (a[i] + a[i+1], i, i+1))
    
    while len(res) < n - 1 and pq:
        s, i, j = heappop(pq)
        res.append(s)
        if j + 1 < n:
            heappush(pq, (a[i] + a[j+1], i, j+1))
            
    return res

    
n = int(input())
a = list(map(int, input().split()))
for _ in range(n - 1):
    a = calc(a)
print(a[0] % MOD)

