#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adj(26);
    vector<int> deg(26);
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    for (int i = 0; i < n - 1; i++) {
        string a = names[i], b = names[i + 1];
        bool ok = false;
        for (int j = 0; j < min(a.size(), b.size()); j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].insert(b[j] - 'a');
                ok = true;
                break;
            }
        }
        if (!ok && a.size() > b.size()) {
            cout << "Impossible" << endl;
            return;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int v : adj[i]) {
            deg[v]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 26; i++) {
        if (deg[i] == 0) pq.push(i);
    }
    set<int> chars;
    for (int i = 0; i < 26; i++) {
        chars.insert(i);
    }
    vector<char> order;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u + 'a');
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                pq.push(v);
            }
        }
        chars.erase(u);
    }
    if (order.size() < 26) {
        cout << "Impossible" << endl;
    } else {
        for (char c : order) cout << c;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
