#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    set<char> st(s.begin(), s.end());
    if (n < k) {
        cout << "impossible" << endl;
    } else {
        cout << max(0LL, k - (int)st.size()) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
