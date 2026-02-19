import sys
from random import randint, shuffle, choice
from math import gcd, sqrt, isqrt, perm, comb, factorial, log2, ceil, floor
from collections import Counter, defaultdict, deque
from functools import lru_cache, reduce, cmp_to_key
from itertools import accumulate, combinations, permutations
from heapq import nsmallest, nlargest, heappushpop, heapify, heappop, heappush
from copy import deepcopy
from bisect import bisect_left, bisect_right
from string import ascii_lowercase, ascii_uppercase
input = lambda: sys.stdin.buffer.readline().decode().rstrip()
OneByOne = lambda: sys.stdin.read(1)
inf = float('inf')
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LI = lambda: list(input().split())
LII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))
yes = lambda: print('YES')
no = lambda: print('NO')
DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1))
DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))
MOD = 10 ** 9 + 7

for _ in range(II()):
    n = II()
    a = LII()
    b = LII()
    d = [a[i] & b[i] for i in range(n)]
    mp = defaultdict(int)
    status = [100000000 for _ in range(n)]
    ans = 0
    intervals = []
    for i in range(n) :
        need = b[i] - d[i]
        if need < 0: ans = -1; break
        for j in range(30) :
            if (a[i] >> j) & 1:
                if (not mp[j]) : ans = -1; break
                status[i] = min(status[i], mp[j])
                intervals.append([mp[j], i]);
        if ans == -1 : break
        for j in range(30) :
            if (a[i] >> j) & 1:
                mp[j] = i
                
    if ans == -1 : 
        print(ans) 
        continue
    for i in range(n) :
        if status[i] ==  100000000 : status[i] = i;
    intervals.sort()
    fin = [intervals[0]]
    for i in range(1, n): 
        if intervals[i] <= fin[-1][1] :
            fin[-1]