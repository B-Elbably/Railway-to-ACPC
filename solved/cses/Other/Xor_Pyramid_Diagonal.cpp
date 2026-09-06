#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1 << 18;
int mask[N];
vector<int> a(N);

int get(int x) {
    int &ret = mask[x];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int sub = x; ; sub = (sub - 1) & x) {
        ret ^= a[sub];
        if (sub == 0)
            break;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    memset(mask, -1, sizeof(mask));
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cout << get(i) << ' ';
    }
    // cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
