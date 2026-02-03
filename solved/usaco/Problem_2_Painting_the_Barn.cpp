#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, ans;
vector<vector<ll>> a, pref;

void build() {
    pref.assign(1002, vector<ll>(1002, 0));
    for (int i = 1; i < 1002; i++){
        for (int j = 1; j < 1002; j++){
            pref[i][j] = a[i][j] 
                        + pref[i - 1][j] + pref[i][j - 1] 
                        - pref[i - 1][j - 1];
            if (pref[i][j] == m) ans++;
        }
    }
}

void print() {
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            cout << pref[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> m;
    a.assign(1002, vector<ll>(1002,  0));
    for (int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        a[x1][y1] += 1;
        a[x1][y2] -= 1;
        a[x2][y1] -= 1;
        a[x2][y2] += 1;
    }
    ans = 0;
    build();
    // print();
    cout << ans << endl;
}
