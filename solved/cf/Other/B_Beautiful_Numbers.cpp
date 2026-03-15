#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {a[i] = s[i] - '0'; freq[a[i]]++;}
    int sum = accumulate(a.begin(), a.end(), 0LL);

    if (sum <= 9) {
        cout << 0 << endl;
        return;
    }
    int target = a[0];
    sort(a.begin(), a.end(), greater<int>()); 
    int ans = 0;
    int rem = sum - 9;
    for (int i = 0; i < n; i++) {
        freq[a[i]]--;
        if (a[i] == target && freq[target] == 0) rem++;
        ans++;
        rem -= a[i];
        if (rem <= 0) break;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}