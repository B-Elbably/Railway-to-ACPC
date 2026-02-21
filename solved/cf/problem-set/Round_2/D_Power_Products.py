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

n, k = MII()
a = LII()
data = defaultdict(int)
ones = 0

def factorize(n) :
    factors = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            cnt %= k 
            if cnt :
                factors.append((i, cnt))
    if n > 1: factors.append((n, 1))
    return factors

for i in a:    
    now = factorize(i)
    if now:
        data[tuple(now)] += 1
    else:
        ones += 1

ans = 0

for i in a:
    now = factorize(i)
    if now :
        data[tuple(now)] -= 1
        target = [(p, (k - c) % k) for p, c in now]
        ans += data[tuple(target)]
        
    else:
        ones -= 1
        ans += ones

print(ans)
