# تعديل حل عمر خالد

import sys
input = lambda: sys.stdin.readline().strip()
for _ in range(int(input())):
    n,q = map(int, input().split())
    nums = list(map(int, input().split()))
    s = list(input())

    # L: swap Lift, R: swap Right
    # shit: swaping in nums does not swap in s

    # i can move L as long as in block of Ls
    # i can move R as long as in block of Rs

    # if i = L and i+1 = R then no move
    # LR is bad only if there is number before L is greater than L 
    # or there is number after R is smaller tha R
    mxs = [0]*n
    mxs[0] = nums[0]
    for i in range(1,n):
        mxs[i] = max(mxs[i-1],nums[i])
    
    mns = [0]*n
    mns[-1] = nums[-1]
    for i in range(n-2,-1,-1):
        mns[i] = min(mns[i+1],nums[i])
    # print(mns,mxs)

    def is_bad(i):
        if i < 0 or i >= n - 1 : return False
        return s[i] == 'L' and s[i+1] == 'R' and mxs[i] > mns[i+1]
    
    bad = 0
    for i in range(n-1):
        if s[i] == 'L' and s[i+1] == 'R':
            bad += is_bad(i)
    # print(bad)
 
    for _ in range(q):
        x=int(input())-1

        bad-=is_bad(x-1)
        bad-=is_bad(x)

        s[x]='L' if s[x]=='R' else 'R'

        bad+=is_bad(x-1)
        bad+=is_bad(x)

        print('YES' if bad==0 else 'NO')
    
