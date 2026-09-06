#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 1;
const int LOG = 20;
int dp[LOG][N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> freq(2 * m + 1, 0), freq2(2 * m + 1, 0);
    int sum = 0;
    for (auto &x : a) {
        cin >> x,
        freq[x]++, sum += x;
    }
    for (int i = 1; i <= 2 * m; ++i) freq[i] += freq[i - 1];

    // int ans = 0;
    // for (int i = 1; i <= m; ++i) {
    //     int sum = freq[m] - freq[i - 1] + freq[i * 2] - freq[i * 2 - 1];
    //     ans = max(ans, sum);
    // }
    vector<int> ans;
    int res = 0;
    for (int k = 1; k <= m; ++k) {
        int mask = (1LL << k);
        if (mask > m) break;
        if (res == sum) break;
        res = 0;
        for (int i = 1; i <= m; ++i) {
            int now = 0;
            for (int j = 1; j < mask; ++j) {
                if (j * i > m) break;
                now += freq[m] - freq[j * i - 1];
            }
            res = max(res, now);
            if (mask * i > m) continue;
            
            now += freq[mask * i] - freq[mask * i - 1];
            res = max(res, now);
        }
        ans.push_back(res);
    }
    while (ans.size() < m) ans.push_back(sum);
    for (auto &x : ans)  cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
