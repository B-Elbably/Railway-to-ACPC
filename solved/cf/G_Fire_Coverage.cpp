#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int l = 0, r = max(n, m) + 1;
    while (l <= r)
    {   
        int mid = (l + r) / 2;
        if (mid == 0) {
            break;;
        }
        int col = (n + mid - 1) / mid;
        int row = (m + mid - 1) / mid;
        if (row * col <= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    cout << l / 2 << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
