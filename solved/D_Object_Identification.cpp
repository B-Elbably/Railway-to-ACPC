#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void answer(char c) {
    cout << "! " << c << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (pos[i] == -1) x = i;
    }

    if (x != -1) {
        answer(ask(x, 1 + (x == 1)) == 0 ? 'A' : 'B');
    } else {
        int go = ask(pos[1], pos[n]);
        int back = ask(pos[n], pos[1]);
        if (go == back && go >= n - 1) {
            answer('B');
        } else {
            answer('A');
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
