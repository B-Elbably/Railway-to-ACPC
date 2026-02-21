#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n , k , x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> idices;
    for (int i = 0; i < n - 1;++i) {
        if (a[i] == a[i + 1] && a[i] == x) {
            idices.push_back(i++);
        }
    }
    int ans = (idices.empty() ? 0 : 2);
    for (int start : idices) {
        int go = start + 2;
        int back = start - 1;
        int cur = 2;
        if (back < 0 || go >= n) continue;
        int target = a[go];
        int cnt = 0;
        while (back >= 0 && go < n)
        {
            if (a[back] != a[go]) break;
            target = a[back];
            while(back >= 0 && a[back] == target){
                cnt++;back--;
            }
            while(go < n && a[go] == target){
                cnt++;go++;
            }
            if (cnt <= 2) break; 
            
            cur += cnt;
            cnt = 0;
        }
        
        ans = max(ans , cur);
    }
    cout << ans; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
