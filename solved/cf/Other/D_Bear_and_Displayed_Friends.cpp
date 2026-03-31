#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k,q;
    cin >> n >> k >> q;
    priority_queue<int> pq;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < q; i++) {
        int tp, idx;
        cin >> tp >> idx;
        if (tp == 1) {
            pq.push(a[idx - 1]);
        }else {
            vector<int> temp;
            int ok = 0;
            while (!pq.empty() && temp.size() < k) {
                temp.push_back(pq.top());
                ok |= (pq.top() == a[idx - 1]);
                pq.pop();
            }
            if (ok) cout << "YES\n";
            else cout << "NO\n";
            for (int x : temp) pq.push(x);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
