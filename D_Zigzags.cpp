#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 3e3 + 5;
int freq[N][N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            freq[i][j] = freq[i - 1][j];    
        cin >> a[i];
        freq[i][a[i]]++;
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt1 = freq[i - 1][a[j]];
            int cnt2 = freq[n][a[i]] - freq[j][a[i]];
            ans += cnt1 * cnt2;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
