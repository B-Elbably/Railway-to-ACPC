#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int mod = 1e9 + 7;
#define tp tuple<int,int,int>

int power(int base, int exp) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

vector<int> calc(vector<int> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> res;
    res.reserve(n - 1);
    priority_queue<tp, vector<tp>, greater<>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({(a[i] + a[i+1]), i, i+1});
    }

    while (res.size() < n - 1) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        res.push_back(sum);
        if (j + 1 < n) {
            pq.push({(a[i] + a[j+1]), i, j+1});
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int k = n; k > 1; k--) {
        sort(a.begin(), a.end());
        int mn = a[0];
        ans = (ans + (mn % mod) * power(2, k - 1)) % mod;
        for (auto &x : a) x -= mn;
        a = calc(a);
    }
    ans = (ans + a[0]) % mod;
    cout << (ans + mod) % mod << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}