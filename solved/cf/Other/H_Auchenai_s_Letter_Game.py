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

def solve():
    a, b, c, x, y, z = MII()
    ans = 0
    igm = gm = im = 0
    res = []
    cnt = min(a, b, c)
    for i in range(cnt + 1):
        a_ = a - i
        b_ = b - i 
        c_ = c - i
        j = k = 0
        if y >= z:
            j = min(b_, c_)
            k = min(a_, c_ - j)
        else:
            k = min(a_, c_)
            j = min(b_, c_ - k)
        sm = (j * y) + (k * z) + (i) * (x + y)
        if (sm > ans) :
            igm = i
            im = k
            gm = j
            ans = sm
    print(ans)
    res = []
    for __ in range(igm):
        res.append("IGM")
    for __ in range(gm):
        res.append("GM")
    for __ in range(im):
        res.append("IM")
    a -= (igm + im)
    b -= (igm + gm)
    c -= (igm + gm + im)
    res.append("I" * a)
    res.append("G" * b)
    res.append("M" * c)
    print("".join(res))


for _ in range(II()):
    solve()