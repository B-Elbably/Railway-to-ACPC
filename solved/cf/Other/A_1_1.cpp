#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "0000";
    int mn = 0, mx = 0;
    int j;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            j = i;
            while (j < n) {
                if ((s[j] == '0' && s[j + 1] == '0')) break;
                j++;
            }
            mx += (j - i);
            mn += (j - i) / 2 + 1;
            i = j;
        } else {
            i++;
        }
    }
    cout << mn << " " << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}