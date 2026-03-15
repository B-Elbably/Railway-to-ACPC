def query(x):
    print(f"? {x}")
    return input()

def solve():
    start = -10**18
    target = query(start)
    step = 1
    while True:
        nxt = start + step
        if nxt > 10**18: nxt = 10**18
        if query(nxt) != target:
            low = start
            high = nxt
            break
        start = nxt
        step *= 2
        
    t1 = high
    while low <= high:
        mid = (low + high) // 2
        if query(mid) != target:
            t1 = mid
            high = mid - 1
        else:
            low = mid + 1
            
    color_t1 = query(t1)
    step = 1
    start = t1
    while True:
        nxt = start + step
        if nxt > 10**18: nxt = 10**18
        if query(nxt) != color_t1:
            low = start
            high = nxt
            break
        start = nxt
        step *= 2
        
    t2 = high
    while low <= high:
        mid = (low + high) // 2
        if query(mid) != color_t1:
            t2 = mid
            high = mid - 1
        else:
            low = mid + 1
            
    print(f"! {t2 - t1}")

for _ in range(int(input())) : 
    solve()