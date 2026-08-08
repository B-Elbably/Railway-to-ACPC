#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void solve() {
    vector<string> a(3);
    int n;
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    for (int i = 1; i < n * 3; i += 3) {
        int x = 1, y = i;
        int res = 0;
        for (int j = 0; j < 8; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= n * 3) continue;
            if (a[nx][ny] == '*') res++;
        }
        ans = max(ans, res * 4);
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
