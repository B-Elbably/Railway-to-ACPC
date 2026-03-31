#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int go = 0;
    int ok = 1;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') go--;
        else go++;
        
        if (go < 0) {
            if(ok) last = i;
            ok = 0;
        }
        if ((go == 0) && ( ok == 0)) {
            ok = 1;
            ans += i - last + 1;
        }
        // cout << go << endl;
    }
    // cout << go << " " << ans << endl ;
    if (go == 0) {
        cout << ans;
    }else {
        cout << -1;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
