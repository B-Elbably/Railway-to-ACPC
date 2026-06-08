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

def lcm(a, b) :
    return a * b // gcd(a, b)

start = 1;
for _ in range(start, start + II()):
    l, r, k = MII()
    # l = 1; r = 500; k = _
    # print(k)
    ans = 0
    for i in range(1, int(r ** 0.5) + 1) :
        if (k % i): continue
        j = k // i
        if gcd(i, j) - 1: continue
        ans += r // j
        ans -= min(r // j + 1, (l + i - 1) // i - 1)
    print(ans)
    # mx = 0;
    # mp = defaultdict(int)
    # for i in range(l, r + 1) :
    #     ans = []
    #     for j in range(i, r + 1) :
    #         if lcm(i, j) // gcd(i, j) == k :
    #             # yes()
    #             # print(i, j)
    #             ans.append((j, gcd(i, j)))
    #             # mp[gcd(i, j)] += 1
    #             # break
    #     mp[ans.__len__()] += 1
    #     # if ans.__len__() > 1 :
    #     #     mx = max(mx, i)
    #         # print(i, ans)
    # for i in range(1, 10) :
    #     if mp[i] > 0 :
    #         print(i, mp[i], r // mp[i])
    # print(ans)
    # print(mx)
    # print("===")