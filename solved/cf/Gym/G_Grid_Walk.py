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
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1))
DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))
MOD = 10 ** 9 + 7

n, m, k, t = MII()
grid = [list(input()) for _ in range(n)]
mp = {"L": "R", "R": "L", "U": "D", "D": "U"}
DIR4 = {
    "L": (0, -1),
    "R": (0, 1),
    "U": (-1, 0),
    "D": (1, 0)
}

xx, yy, d = [], [], []
for _ in range(k):
    x, y, dd = input().split()
    x = int(x) - 1
    y = int(y) - 1
    xx.append(x); yy.append(y)
    d.append(dd)

for _ in range(t):
    for i in range(k):
        dx, dy = DIR4[d[i]]
        nx, ny = xx[i] + dx, yy[i] + dy
        if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '.':
            xx[i], yy[i] = nx, ny
        else:
            d[i] = mp[d[i]]

for i in range(k):
    print(xx[i] + 1, yy[i] + 1, d[i])