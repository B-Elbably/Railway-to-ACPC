from itertools import permutations

def dist(x1 , y1 , x2 , y2):
    return (x1 - x2) ** 2 + (y1 - y2) ** 2


x1 , y1 = map(int , input().split())
x2 , y2 = map(int , input().split())
x3 , y3 = map(int , input().split())


ls = [[x1 , y1] , [x2 , y2] , [x3 , y3]]


res1 = []
for i in range(3):
    for j in range(i + 1 , 3):
        x = dist(ls[i][0] , ls[i][1] , ls[j][0] , ls[j][1])
        res1.append(x)


x4 , y4 = map(int , input().split())
x5 , y5 = map(int , input().split())
x6 , y6 = map(int , input().split())

lst = [[x4 , y4] , [x5 , y5] , [x6 , y6]]


res2 = []

for i in range(3):
    for j in range(i + 1 , 3):
        x = dist(lst[i][0] , lst[i][1] , lst[j][0] , lst[j][1])
        res2.append(x)


res1.sort()

res2.sort()


for perm in permutations(res1):
    xx = list(perm)
    st = set()
    for i in range(3):
         x = res2[i] / xx[i]
         st.add(x)
    if len(st) == 1 : 
        print("YES")
        quit()
print("NO")