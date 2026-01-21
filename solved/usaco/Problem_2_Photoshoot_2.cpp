#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int>  a(n), b(n), moved(n , 0);
    for (int i = 0; i < n; i++) { cin >> a[i]; a[i]--; }
    for (int i = 0; i < n; i++) { cin >> b[i]; b[i]--; }
    int ans = 0, j = 0;
    for (int i = 0; i < n; i++) {
        while(j < n && moved[a[j]]) ++j;
        if (b[i] == a[j]) ++j;
        else {
            ans++;
            moved[b[i]] = 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
