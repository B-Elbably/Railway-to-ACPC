#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<ll>> a, pref;

void build() {
    pref.assign(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pref[i][j] = a[i][j] 
                        + pref[i - 1][j] + pref[i][j - 1] 
                        - pref[i - 1][j - 1];
}

ll query(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    build();
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }
}
