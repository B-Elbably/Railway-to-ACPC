import sys
input = sys.stdin.readline

def solve():
    s = [x for x in input().strip()]
    n = len(s)
    inds = [0 for _ in range(26)]
    for i in range(n):
        inds[ord(s[i]) - ord("a")] = i 
    st = set()
    ind = 0 
    st.add(ord(s[0]) - ord("a"))
    res = []
    for i in range(n):
        mx = -1
        jj = -1
        for j in range(26):
            if j not in st : 
                if inds[j] > mx : 
                    mx = inds[j]
                    jj = j   
        if mx > ind :
            ind = mx 
            st.add(jj)
        else : 
            res.append(ind)
            st.clear()
    print(res)
# for _ in range(int(input())):
solve()