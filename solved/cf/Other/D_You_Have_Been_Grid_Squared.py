from collections import defaultdict
for _ in range(int(input())):
    n = int(input())
    a = [[0] * n for _ in range(n)]
    s = set()
    d = defaultdict(list)
    for j in range(n):
        res = 0
        for i in range(n):
            if i == 0:
                a[i][j] = j + 1
            else:
                a[i][j] = a[i - 1][j] * a[i - 1][j]
            if a[i][j] in s: continue
            res += 1
            s.add(a[i][j])
        # print(f"{j + 1} -> {res}")
        d[res].append(j + 1)
    # print(sorted(s))
    # print(len(s))
    print("==================================")
    for k in sorted(d.keys()):
        print(f"{k}: -> {d[k]}")
    print("==================================")


# for _ in range(int(input())) :
#     n = int(input())
#     arr = [list(range(1 , n + 1)) for _ in range(n)]
#     # data = defaultdict(list)
#     data = set(range(1 , n + 1))
#     for i in range(1, n) :
#         for j in range(0, n) :
#             arr[i][j] = arr[i - 1][j] * arr[i - 1][j]
#             data.add(arr[i][j])
#     print(len(data))
# # 4 * 4
# 16
# 2 3