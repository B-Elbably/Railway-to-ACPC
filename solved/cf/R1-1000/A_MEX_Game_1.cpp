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
    map<int, int> freq;
    sort(all(a));
    for (auto &x : a) freq[x]++;
    bool bad = false;
    for (int i = 0; i <= n; ++i) {
        if (!freq[i] || (freq[i] == 1 && bad)) {
            cout << i << endl;
            return;
        }
        bad |= (freq[i] == 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
