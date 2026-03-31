def clc(difs , x):
    rem = x
    for i in range(len(difs)):
        mx = difs[i] - rem - 1
        if mx < 1:
            return False
        rem = mx
    return True

def solve():
    n = int(input())
    res = []
    for i in range(n):
        x ,y = map(int, input().split())
        res.append([x , y])
    difs = []
    for i in range(len(res) - 1):
        x1 , y1 , x2 , y2 = *res[i] , *res[i  + 1]
        if x1 == x2:
            difs.append(abs(y1 - y2))
        else:
            difs.append(abs(x1 - x2))

    mi = min(difs)
    if mi - 2 <= 0:
        print(-1)
        return 

    if clc(difs , mi - 2):
        print(mi - 2)
    else : 
        print(-1)

solve()



