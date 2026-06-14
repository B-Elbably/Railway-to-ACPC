#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    // n = min(n, m + (n % 3));
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    vector<int> ok;
    ok.push_back((a[m - 1] ^ a[m - 2]));
    ok.push_back((a[m - 1] ^ ok[0]));
    ok.push_back((ok[0] ^ ok[1]));
    int sum = 0;
    for (int i = 0; i < m; i++) sum ^= a[i];
    vector<int> freq(3);
    freq[0] = (n - m + 2) / 3;
    freq[1] = (n - m + 1) / 3;
    freq[2] = (n - m) / 3;
    if (freq[0] % 2 == 1) sum ^= ok[0];
    if (freq[1] % 2 == 1) sum ^= ok[1];
    if (freq[2] % 2 == 1) sum ^= ok[2];
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
