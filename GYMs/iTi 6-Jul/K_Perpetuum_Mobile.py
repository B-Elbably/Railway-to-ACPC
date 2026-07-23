n , m = map(int , input().split())


tot = (n * (n - 1)) // 2
dif = tot - m 
ls = [x for x in range(n , 0 , -1)]

lst = []

cur = n - 1
for i in range(n - 1 , -1 , -1):
    if dif - cur >= 0:
        lst.append(ls[i])
        dif -= cur 
        cur -= 1 
        ls.pop()
    else : 
        break


ls = lst + ls 


r = n - 1
while dif : 
    ls[r] , ls[r - 1] = ls[r-1] , ls[r]
    r-=1 
    dif -= 1
print(*ls)
