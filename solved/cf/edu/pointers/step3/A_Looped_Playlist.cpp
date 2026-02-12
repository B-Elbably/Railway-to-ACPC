#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n * 5);
    int total = 0;
    for (int i = 0; i < n; i++){ 
        cin >> a[i]; total += a[i];
        for (int j = 1; j < 5; j++)
            a[i + j * n] = a[i];
    }

    int loops = max(0LL, (x - 1) / total - 2);
    x -= loops * total;

    int l = 0, sum = 0,len = 1e18, idx = -1;

    for (int r = 0; r < a.size(); r++) {
        sum += a[r];
        while (l <= r && sum - a[l] >= x) sum -= a[l++];
        if (sum >= x && r - l + 1 < len) {
            len = r - l + 1;
            idx = l % n + 1;
        }
    }

    cout << idx << " " << len + loops * n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
