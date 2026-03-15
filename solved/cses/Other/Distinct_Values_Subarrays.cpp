#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    set<int> s;
    int r = n - 1;
    
    for (int i = n - 1; i >= 0; i--) {
        while (s.count(a[i]))
        {
            s.erase(a[r--]);
        }
        s.insert(a[i]);
        ans += s.size();
    }   
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
