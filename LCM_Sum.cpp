#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int MAX = 1e6 + 5;
vector<int> phi(MAX + 1);
vector<int> res(MAX + 1);
void buildPhi() {
    for (int i = 0; i <= MAX; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            res[j] += (i * phi[i]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ((res[n] + 1) * n / 2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildPhi();
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
