#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 24;
int mask[1 << N];

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int m = s.size();
        int msk = 0;
        for (int j = 0; j < m; ++j) {
            msk |= (1 << (s[j] - 'a'));
        }
        mask[msk]++;
    }
    for (int i = 0; i < N; ++i) {
        for (int msk = 0; msk < (1 << N); ++msk) {
            if ((msk >> i) & 1) {
                mask[msk] += mask[msk ^ (1 << i)];
            }
        }
    }
    int ans = 0;
    for (int msk = 0; msk < (1 << N); ++msk) {
        int valid = n - mask[msk];
        ans ^= (valid * valid);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
