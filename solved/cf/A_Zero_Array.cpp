#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> freq;
    for (auto &x : a) {
        cin >> x;
        if (x) freq[x]++;
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int idx, v; 
            cin >> idx >> v;
            idx--;
            if (a[idx]) freq[a[idx]]--;
            if (freq[a[idx]] == 0)  freq.erase(a[idx]);
            a[idx] = v;
            if (a[idx]) freq[a[idx]]++;
        }else {
            cout << freq.size() << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
