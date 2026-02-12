n, m = map(int, input().split())
perms = []

def build(i, a_now) :
    if i == n: 
        perms.append(a_now.copy())
        return
    build(i + 1, a_now + [1])
    build(i + 1, a_now + [a_now[-1] + 1])

ans = build(1, [1])
for perm in perms:
    print(perm)