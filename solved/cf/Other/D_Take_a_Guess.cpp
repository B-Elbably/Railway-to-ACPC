#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int ask(int i, int j) {
    int OR, AND, XOR;
    cout << "and " << i << " " << j << endl;
    cout.flush();
    cin >> AND;

    cout << "or " << i << " " << j << endl;
    cout.flush();
    cin >> OR;

    XOR = ~AND & OR;
    int res = 2 * AND + XOR;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // (a + b) = 2 * (a & b) + XOR
    int ab = ask(1 , 2);
    int bc = ask(2 , 3);
    int ac = ask(1 , 3);
    int a = ab - bc + ac; a /= 2;
    priority_queue<int> pq;
    pq.push(a); pq.push(ab - a); pq.push(ac - a);
    for (int i = 4; i <= n; ++i) {
        int ai = ask(1, i);
        pq.push(ai - a);
    }
    while (pq.size() != k) pq.pop();
    cout << "finish " << pq.top();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
