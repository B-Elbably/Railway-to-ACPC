#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
int freq[N];
int p[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        p[x] = y;
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        freq[x]++;
    }    
    for (int i = 0; i < N; ++i) p[i] = i;
    int ans = 0;
    int edges = 0;
    
    for (int i = N - 1; i >= 1; --i) {
        if (edges == n - 1) break;
        int first = -1;
        for (int j = i; j < N; j += i) {
            if (freq[j]) {
                if (first == -1) {
                    first = j;
                } else if (unite(first, j)) {
                    ans += i;
                    edges++;
                    if (edges == n - 1) break;
                }
            }
        }
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}