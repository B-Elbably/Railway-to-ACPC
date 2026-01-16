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

# ans = [[] for _ in range(1001)]
# for i in range(1, 1001):
#     if i & 1 :
#         ans[i] = ans[i -1] + [i]
#     else :
#         ans[i] = ans[i // 2] + [i]

# print(*list(range(1, 17)))

def f(x) :
    res = 0
    while x:
        res += (x & 1)
        x -= (x & 1)
        res += x > 0
        x >>= 1
    return res

# for i in range(1, 17):
#     print(i , ans[i], bin(i)[2:], len(ans[i]), f(i))

for i in range(1, 17):
    print(i , f(i))
    

for _ in range(II()):
    n , k = MII()   
    sm = 0
    for i in range(1, n + 1):
        sm += f(i) > k 
    print(sm)
    
    
