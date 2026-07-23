



def solve():
    ls = []
    n = int(input())
    for i in range(n):
        a , b = map(int , input().split())
        ls.append([a , b])
        
    m = int(input())
    lst = list(map(int , input().split()))
    
    lst = [[lst[i] , i] for i in range(m)]
    lst.sort()
    
    diff = [0 for _ in range(m + 10)]
   
    for i in ls: 
        a , b = i 
        
        if a > 0 and b >= 0 : 
            lo = 0
            hi = m-1
            ans = -1
            while lo <= hi: 
                mid = (lo + hi) // 2 
                if lst[mid][0] >= b:
                    ans = mid 
                    hi = mid - 1 
                else : 
                    lo = mid + 1 
            if ans == -1:
                # print(a , b , 1)
                continue
    
            diff[ans] += 1 
            diff[-1] -= 1 
        elif a < 0 and b <= 0 : 
            lo = 0
            hi = m-1
            ans = -1
            while lo <= hi: 
                mid = (lo + hi) // 2 
                if lst[mid][0] <= b:
                    ans = mid 
                    lo = mid + 1 
                else : 
                    hi = mid - 1 
            if ans == -1:
                # print(a , b , 2)
                
                continue
            diff[ans + 1] -= 1 
            diff[0] += 1
        elif a < 0 and b >= 0:
            
            lo = 0
            hi = m-1
            ans = -1
            while lo <= hi: 
                
                
                mid = (lo + hi) // 2
                # print(mid) 
                if lst[mid][0] <= -b:
                    ans = mid 
                    lo = mid + 1
                else : 
                    hi = mid - 1 
            if ans == -1:
                print(a , b , 3)
                
                continue
            diff[ans + 1] -= 1 
            diff[0] += 1
        else : 
            lo = 0
            hi = m-1
            ans = -1
            while lo <= hi: 
                mid = (lo + hi) // 2 
                if lst[mid][0] >= -b:
                    ans = mid 
                    hi = mid - 1 
                else : 
                    lo = mid + 1 
            if ans == -1:
                continue
            diff[ans] += 1 
            diff[-1] -= 1
        # print(diff)
            
            
    for i in range(1 , len(diff)):
        diff[i] += diff[i - 1]
    ans = [x for x in range(m + 1)]
    for i in range(m):
        ans[lst[i][1]] = diff[i]
    for i in range(m):
        print(ans[i])
        
solve()