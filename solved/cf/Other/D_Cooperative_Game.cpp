#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int ask(string nodes) {
    cout << "next ";
    for (char c : nodes) {
        cout << c << " ";
    }
    cout << endl;
    cout.flush();
    int n; cin >> n;
    string res;
    for (int i = 0; i < n; i++) {
        cin >> res;
    }
    return n;
}

void solve() {
    int result = ask("01");
    result = ask("1");
    while (result != 2) {
        result = ask("01");
        result = ask("1");
    }
    while (result != 1) {
        result = ask("0123456789");
    }
    cout << "done";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
