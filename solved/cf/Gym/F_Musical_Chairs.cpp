#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, p;
const int N = 1001;
vector<int> song, chair;
int bad[N];
// int cnt = 0;
// bool go(int i, int cur) {
//     if (i == n) return 1;
//     int op1 = (cur + song[i]) % n;
//     if (!op1) op1 = n;
//     int op2 = (cur - song[i] + n) % n;
//     if (!op2) op2 = n;
//     bool res = 0;
//     bad[chair[i]] = 1;
//     if (!bad[op1]) res |= go(i + 1, op1); 
//     if (!bad[op2]) res |= go(i + 1, op2); 
//     // cnt++;
//     return res;
// }

void solve() {
    cin >> n >> p;
    song.resize(n - 1);
    chair.resize(n - 1);
    for (auto &x : song) cin >> x;
    for (auto &x : chair) cin >> x;
    queue<int> q;
    q.push(p);
    int oo = 0;
    while ((oo < n - 1) && (!q.empty())) {
        bad[chair[oo]] = 1;
        vector<int> good;
        vector<int> idx(N);
        for (int i = 1; i <= n; i++) {
            if (bad[i]) continue;
            idx[i] = good.size();
            good.push_back(i);
        }
        int m = good.size();
        set<int> ss;
        while (!q.empty()) {
            ss.insert(q.front());
            q.pop();
        }
        for (int i : ss) {
            int cur = idx[i];
            int op1 = (cur + song[oo]) % m;
            if (!op1) op1 = n;
            q.push(good[op1]);
            int op2 = (cur - (song[oo] % m) + m) % m;
            if (!op2) op2 = n;
            q.push(good[op2]);
        }
        oo++;
    }

    cout << (q.size() ? "Yes": "No");
    // cout << cnt;
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
