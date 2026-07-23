#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    if ((n == k) && (n != 1)){
        cout << -1;
        return ;
    }
    int cur = k;
    int ans = -1; 
    for(int i = 1 ; i <= n / k ; i++){
        if ((i - 1) * k + (n - (k * i)) < (k-1)){
            cout << -1 << endl; 
            return ; 
        }
        ans = max(ans , i - 1 + (k - 1));
        // cout << "Sad " << ans << endl;
    }
    
    if (n % k != 0){
        if ((n / k) * k >= k -1){
            ans = max(ans , n / k + (n % k - 1));
        }else {
            cout << -1 << endl; 
            return ;
        }
    }

    cout << ans << '\n';
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
