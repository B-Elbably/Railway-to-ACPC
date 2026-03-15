#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 1;
vector<int> ans(N);

void build() {
    for (int i = 0; i < N; i++) ans[i] = 1;
    for (int i = 2;i < N; i++) {
        for (int j = i; j < N; j += i) {
            ans[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int ai; cin >> ai;
        cout << ans[ai] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
