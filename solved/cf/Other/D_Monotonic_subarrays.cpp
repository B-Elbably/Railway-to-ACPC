// solution of: https://codeforces.com/contest/475/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct sparseTable
{
    vector<vector<int>> sparse ; 
    vector<int> a , LOG; 
    int n ; 

    sparseTable(vector<int> v){
        a = v ; 
        n = v.size() ;
        LOG.resize(n + 1 , 0);
        sparse.resize(n , vector<int>(20)) ;
        build() ; 
    }

    int merge(int x , int y){
        return gcd(x , y) ;
    }

    void build() {
        for (int i = 0 ; i < n ; ++i){
            sparse[i][0] = a[i] ; 
            LOG[i + 2] = LOG[(i  + 2) / 2] + 1 ;
        }

        for (int k = 1 ; k < 20 ; ++k) {
            for (int i = 0 ; i + (1 << k) - 1 < n ; ++i){
                sparse[i][k] = merge(
                        sparse[i][k-1] ,  
                        sparse[i + (1 << (k - 1))][k - 1]) ;
            }
        }
    }
    
    int query(int l , int r){
        int k = LOG[r - l + 1] ;
        return merge(sparse[l][k] , sparse[r - (1 << k) + 1][k] )  ;
        // return dt[vlu] ;
    }
    
};

void solve() {
    int n , q ;
    cin >> n  ; 
    vector<int> a(n) ;
    for (int i = 0 ; i < n ; ++i) cin >> a[i] ; 
    sparseTable sp(a) ;
    cin >> q ; 
    map<int , ll> mp ; 
    int curGCD ;
    
    for (int i = 0 ; i < n ; ++i) {
        int L = i  ; 
        while (L < n)
        {
            curGCD = sp.query(i , L) ; 
            int l = L, r = n - 1, last = L ; 
            while (l <= r) {
                int mid = (l + r) / 2  ;
                if (sp.query(i , mid) == curGCD){
                    last = mid ;
                    l = mid + 1 ;
                }else {
                    r = mid - 1 ; 
                }
            }
            mp[curGCD] += last - L + 1 ;
            L = last + 1 ;  
        }
        
    }
    int vlu ;
    while (q--){
        cin >> vlu ; 
        cout << mp[vlu] << "\n";
    } 
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}