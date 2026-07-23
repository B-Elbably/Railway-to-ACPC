s = input()

mp = {}
for i in s : 
    mp[i] = mp.get(i , 0) + 1 

n = len(s)


ans = 0
for j in mp:
        ans += ((mp[j]/n) * (mp[j]/n))
        
print(ans * n)