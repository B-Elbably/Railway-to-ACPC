for _ in range(int(input())):
    h, c, t = map(int, input().split())
    if h + c >= 2 * t:
        print(2)
        continue
    
    l = 1; r = 10 ** 9
    ans = 1
    while l <= r:
        m = (l + r) // 2
        m |= 1 
        avg = (h + c) * (m // 2) + h
        if avg >= t * m:
            ans = m
            l = m + 2
        else:
            r = m - 2
            
    a, b = ans, ans + 2
    d1 = abs((h + c) * (a // 2) + h - t * a) * b
    d2 = abs((h + c) * (b // 2) + h - t * b) * a
    
    print(a if d1 <= d2 else b)