#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    while (n > 9) {
        st.push(9);
        n -= 9;
    };
    st.push(n);
    while (!st.empty()) cout << st.top(), st.pop();

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
