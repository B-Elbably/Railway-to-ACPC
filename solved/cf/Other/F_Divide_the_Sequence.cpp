#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        sum += x;
        if (i < n - 1) {
            p.push_back(sum);
        }
    }
    sort(p.begin(), p.end());
    int sum_s = 0;
    for (int i = 1; i <= n; ++i) {
        cout << i * sum - sum_s << " ";
        if (i < n) sum_s += p[i - 1];
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
