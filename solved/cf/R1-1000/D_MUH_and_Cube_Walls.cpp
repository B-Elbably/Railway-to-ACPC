#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 4e5 + 15;
int pi[N];
void KMP(const vector<int> &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) pi[i] = 0;
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = 0;
    vector<int> temp;
    for (int j = 1; j < w; j++) {
        temp.push_back(b[j] - b[j - 1]);
    }
    temp.push_back(-1e9);
    for (int i = 1; i < n; i++) {
        temp.push_back(a[i] - a[i - 1]);
    }
    KMP(temp);
    for (int i = w; i < n + w; i++) {
        ans += (pi[i] == w - 1);
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
