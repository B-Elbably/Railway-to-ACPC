#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 5e5 + 5;
int ans[N];
void precompute() {
    for (int i = 1; i < N; i++) {
        for (int j = i * 2; j < N; j += i) {
            ans[j] += i;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
