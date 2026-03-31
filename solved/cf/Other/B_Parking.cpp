#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int ai;
    for (int i = 0; i < n; ++i){
        cin >> ai;
        auto it = st.lower_bound(ai);
        if (it == st.end()) 
            it = st.begin();
        cout << *it << " ";
        st.erase(it);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
