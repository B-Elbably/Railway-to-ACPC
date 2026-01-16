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
from operator import mul

# N = 25
# data = [0] * (N)

# # n = II()
# for n in range(2, N) :
#     numbers = list(range(1 , n))
#     ans = []
#     for i in range(1 , n) :
#         for comb in combinations(numbers, i) :
#             if reduce(mul, list(comb)) % n == 1 :
#                 if len(comb) > len(ans) :
#                     ans = list(comb)
#     # print(ans)
#     data[n] = ans
# print(data[1:])

def solve(n):
    if n in [2, 3, 4, 6]:
        print(1)
        return [1]
        
    res = [1]
    go = 1
        
    for i in range(3 - (n & 1), n - 1, 2 - (n & 1)):
        if gcd(i, n) == 1:
            res.append(i)
            go = (go * i) % n
    if (go * (n - 1) ) % n == 1:
        res.append(n - 1)
    print(len(res))
    return res

# [2, 3, 4, 6] -> 1
# 10 -> [1, 3, 7] 1 3 7 9
# for n in range(2, N) :
#     if data[n] == [1]: continue
#     if "".join(map(str, data[n])) != "".join(map(str, solve(n))):
#         print(n, data[n], solve(n))
# # 

print(*solve(II()))