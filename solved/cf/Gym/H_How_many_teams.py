n, k = map(int, input().split())
a = []
for _ in range(n):
    a.append(int(input(), 2))
    
q = int(input())
for _ in range(q):
    x = int(input(), 2)
    ans = 0;
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                if a[i] | a[j] | a[k] == x:
                    ans += 1
    print(ans)