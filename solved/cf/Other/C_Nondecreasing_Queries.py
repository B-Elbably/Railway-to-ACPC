n = int(input())
def ask(l, r):
    print("?", l , r)
    return int(input())

def ans(i) :
    exit(print("!", i))
    
if (ask(1, 1)) :
    ans(1)

sz = 1
while 1:
    lx = min(n, sz + 1)
    rx = min(n, sz * 2)
    # print(lx, rx, sz)
    if (rx - lx + 1 != sz) :
        # lx = rx - sz + 1
        ok2 = 1
    else :
        ok2 = ask(lx, rx)
    if (ok2):
        l = min(n, sz + 1)
        r = min(n, sz * 2)
        while (l <= r) :
            m = (l + r) // 2
            if (ask(m - sz, m)):
                r = m - 1
            else :
                l = m + 1
        ans(r + 1)
    sz *= 2
    # print(sz)