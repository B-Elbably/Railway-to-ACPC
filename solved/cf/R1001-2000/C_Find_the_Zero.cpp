#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i+= 2) {
        int x = ask(0, i);
        if (x) {
            cout << "! " << i + 1 << endl;
            cout.flush();
            return;
        }
    }
    int ok = ask(0, 2);
    if (ok) {
        cout << "! 3" << endl;
        cout.flush();
    }else {
        cout << "! 2" << endl;
        cout.flush();
    }

}
// 0 3 0 4 0 2 0 1
// 3 0 4 0 2 0 1 0


// 1 0 0 2 3 0 0 4



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
