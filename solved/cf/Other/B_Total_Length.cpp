#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, sum = 0, ans = 0;

    for(int r = 0; r < n; r++){
        sum += a[r];
        while(sum > s) sum -= a[l++];
        int len = r - l + 1;
        ans += len * (len + 1) / 2;
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
