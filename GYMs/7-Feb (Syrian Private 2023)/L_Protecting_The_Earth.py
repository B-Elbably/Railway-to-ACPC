def check(mid , k):
    x = mid * 2 + 1
    cur = x // 2 + 1
    return   2*(cur * cur) - x >= k 


for k in range(2, 1000000):
    # k = int(input())
    lo = 1 
    hi = int(1e9)


    ans = -1
    while lo <= hi:
        mid = (lo + hi) // 2 
        if check(mid , k):
            hi = mid - 1 
            ans = mid 
        else : 
            lo = mid + 1 
    # print(ans)
    ans1 = ans


    ans = 0;
    add = 4;
    now = 1;
    while now < k:
        ans += 1;
        now += add;
        add += 4;
    ans2 = ans
    if (ans1 != ans2):
        print(k , ans1 , ans2)

