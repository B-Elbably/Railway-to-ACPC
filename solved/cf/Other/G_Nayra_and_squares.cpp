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
    for (int i = 0; i < n; i++) {
        ans += a[i] * a[i];
    }
    int sq = sqrt(ans);
    while ((sq + 1) * (sq + 1) <= ans) sq++;
    while (sq * sq > ans) sq--;
    cout << sq << "\n";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
