#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        auto it = st.upper_bound(ai);
        if (it != st.end()) {
            st.erase(it);
        }
        st.insert(ai);
    }
    cout << st.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}