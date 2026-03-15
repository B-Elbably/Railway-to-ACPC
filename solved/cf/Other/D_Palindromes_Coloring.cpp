#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    string a;
    cin >> n >> k >> a;
    vector<int> freq(26, 0);
    for (char x : a) freq[x - 'a']++; 
    int ans = 0, odd = 0;
    for (int i = 0; i < 26; i++) {
        ans += freq[i] / 2;
        odd += freq[i] & 1;
    }
    odd += 2 * (ans % k) - k;
    ans = ans / k * 2;
    cout << ans + (odd >= 0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}