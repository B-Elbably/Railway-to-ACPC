#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int calc(int ai, int aj, int x) {
    return (ai ^ x) & (aj ^ x);
}

void solve() {
    int n, K;
    cin >> n >> K;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    
    int mx = -1, ix = -1, jx = -1, x = -1;
    for (int i = 0; i < n - 1; i++) {
        int candy = 0;
        for (int k = 0; k < K; ++k) {
            if ((a[i].first >> k) & 1) continue;
            if ((a[i + 1].first >> k) & 1) continue;
            candy += (1LL << k);
        }
        
        int now = calc(a[i].first, a[i + 1].first, candy);
        if (now > mx) {
            mx = now;
            ix = a[i].second;
            jx = a[i + 1].second;
            x = candy;
        }
    }  
    cout << ix << " " << jx << " " << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}