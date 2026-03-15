#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> freq;
    int l = 0, ans = 0, distinct = 0;
    for (int r = 0; r < n; r++) {
        distinct += (freq[a[r]] == 0);
        freq[a[r]]++;
        while (distinct > k) {
            freq[a[l]]--;
            if (freq[a[l++]] == 0) {
                distinct--;
            }
        }
        ans += (r - l + 1);
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}