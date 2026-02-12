import sys
input = lambda: sys.stdin.readline().strip()
n,k = map(int, input().split())
nums = list(map(int, input().split()))
z = nums.count(0)
x = k//2
if z <= x:
    print(0)
    exit()
res = []
# op i then i + 1 if i is 0
# this flips i and i + k
for i in range(n):
    if nums[i] == 0:
        if i + k < n:
            res.append(i+1)
            res.append(i+2)
            nums[i] = 1
            nums[i+k] ^= 1

# print(nums)
y = nums[n-k:].count(0)
if y > x:
    res.append(n-k+1)

# print(res)
print(len(res))
print(*res)