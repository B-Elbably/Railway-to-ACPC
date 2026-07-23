#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int parse(string &s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m; 
}
void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ok = 1;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        string s; int d;
        cin >> s >> d;
        int t = parse(s);
        if (t + d > 1440) {
            continue;
        }
        v.emplace_back(t, t + d);
    }
    if (ok) {
        n = v.size();
        sort(all(v));
        for (int i = 0; i < n; ++i) {
            if (pq.size() < m) {
                pq.push(v[i].second);
            } else {
                if (pq.top() > v[i].first) {
                    ok = 0;
                    break;
                } else {
                    pq.pop();
                    pq.push(v[i].second);
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
