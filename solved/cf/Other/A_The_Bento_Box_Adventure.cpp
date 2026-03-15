#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    set<int> st = {1, 2, 3, 4, 5};
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        st.erase(x);
    }
    cout << *st.begin() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
