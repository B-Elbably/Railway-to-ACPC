#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
int freq[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    priority_queue<int> pq;
    for (int i = 1; i < N; ++i) {
        int cnt = 0;
        for (int j = i; j < N; j += i) {
            cnt += freq[j];
        }
        for (int j = 1; j < cnt; ++j) {
            pq.push(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
