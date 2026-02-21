#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n1, n2, n3, n4; 
int m1, m2, m3;
vector<pair<int,int>> a, b, c, d;
unordered_map<int,unordered_set<int>> Yab, Ybc, Ycd;

void input() {
    cin >> n1 >> n2 >> n3 >> n4;
    int ai;
    a.clear(); b.clear(); c.clear(); d.clear();
    Yab.clear(); Ybc.clear(); Ycd.clear();

    for (int i = 0; i < n1; i++) { cin >> ai; a.emplace_back(ai,i); }
    for (int i = 0; i < n2; i++) { cin >> ai; b.emplace_back(ai,i); }
    for (int i = 0; i < n3; i++) { cin >> ai; c.emplace_back(ai,i); }
    for (int i = 0; i < n4; i++) { cin >> ai; d.emplace_back(ai,i); }

    sort(all(a)); sort(all(b)); sort(all(c)); sort(all(d));

    int x,y;
    cin >> m1; while(m1--) { cin >> x >> y; Yab[--y].insert(--x); }
    cin >> m2; while(m2--) { cin >> x >> y; Ybc[--y].insert(--x); }
    cin >> m3; while(m3--) { cin >> x >> y; Ycd[--y].insert(--x); }
}

vector<pair<int,int>> handle(const vector<pair<int,int>> &prev, const vector<pair<int,int>> &cur,
                                    unordered_map<int,unordered_set<int>> &bad) {
    vector<pair<int,int>> res(cur.size(), {1e18,-1});
    for (auto &[cv, ci] : cur) {
        for (auto &[pv, pi] : prev) {
            if (!bad.count(ci) || !bad[ci].count(pi)) {
                res[ci] = {min(res[ci].first, cv + pv), ci};
                break;
            }
        }
    }
    return res;
}

void solve() {
    vector<pair<int,int>> b_new = handle(a, b, Yab);
    vector<pair<int,int>> c_new = handle(b_new, c, Ybc);
    vector<pair<int,int>> d_new = handle(c_new, d, Ycd);

    int res = 1e18;
    for (auto &[val,_] : d_new) res = min(res, val);
    if (res >= 1e18) res = -1;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
}
