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


class SparseTable:
    def __init__(self, arr):
        self.n = len(arr)
        self.k = self.n.bit_length()
        self.st = [[0] * self.k for _ in range(self.n)]
        
        for i in range(self.n):
            self.st[i][0] = arr[i]
            
        for j in range(1, self.k):
            length = 1 << (j - 1)
            for i in range(self.n - (1 << j) + 1):
                self.st[i][j] = max(self.st[i][j - 1], self.st[i + length][j - 1])

    def query(self, l, r):
        if (r < l):
            return -inf
        j = (r - l + 1).bit_length() - 1
        return max(self.st[l][j], self.st[r - (1 << j) + 1][j])


for _ in range(II()):
    n, m, k = MII()
    a = [LII() for _ in range(n)]
    if k == 1 :
        print(0)
        continue
    mn = [inf] * m
    mx = [-inf] * m
    # aa = [[inf, -inf] for _ in range(m)]
    # print(aa)
    for j in range(m):
        for i in range(n):
            mn[j] = min(mn[j], a[i][j])
            mx[j] = max(mx[j], a[i][j])
            # aa[j][0] = min(aa[j][0], a[i][j])
            # aa[j][1] = max(aa[j][1], a[i][j])
    st = SparseTable(mx)
    # aa.sort(key=lambda x: (x[1], x[0]))
    ans = 0;
    for i in range(0, m) :
        res = st.query(0, i - 1)
        if (i + 1 < m):
            res = max(res, st.query(i + 1, m - 1))
        ans = max(ans, res - mn[i])
    print(ans)

    # print(aa[-1][-1] - aa[0][0])