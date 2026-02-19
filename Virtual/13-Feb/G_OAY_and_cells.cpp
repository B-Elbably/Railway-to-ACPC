#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    int ans = 0, left = 0, right = n - 1;      
    while (left <= right) {
        while (left <= right && s[left] != 'L') left++;
        while (left <= right && s[right] != 'R') right--;
        if (left > right) break;
        
        ans += pref[right-- + 1] - pref[left++];
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}