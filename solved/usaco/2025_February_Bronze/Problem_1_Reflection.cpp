#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<vector<char>> a;
int calc(){
    int res = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            int cnt[2] = {0, 0};
            cnt[a[i][j] == '.' ? 0 : 1]++;
            cnt[a[i][n - j - 1] == '.' ? 0 : 1]++;
            cnt[a[n - i - 1][j] == '.' ? 0 : 1]++;
            cnt[a[n - i - 1][n - j - 1] == '.' ? 0 : 1]++;
            res += min(cnt[0], cnt[1]);
        }
    }
    return res;
}

void solve() {
    int q;
    cin >> n >> q;
    a.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) cin >> a[i][j];

    int res = calc();
    cout << res << endl;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        int cnt[2] = {0, 0};
        cnt[a[i][j] == '.' ? 0 : 1]++;
        cnt[a[i][n - j - 1] == '.' ? 0 : 1]++;
        cnt[a[n - i - 1][j] == '.' ? 0 : 1]++;
        cnt[a[n - i - 1][n - j - 1] == '.' ? 0 : 1]++;
        res -= min(cnt[0], cnt[1]);

        cnt[0] = cnt[1] = 0;
        a[i][j] = (a[i][j] == '.' ? '#' : '.');
        cnt[a[i][j] == '.' ? 0 : 1]++;
        cnt[a[i][n - j - 1] == '.' ? 0 : 1]++;
        cnt[a[n - i - 1][j] == '.' ? 0 : 1]++;
        cnt[a[n - i - 1][n - j - 1] == '.' ? 0 : 1]++;
        res += min(cnt[0], cnt[1]);
        cout << res << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
