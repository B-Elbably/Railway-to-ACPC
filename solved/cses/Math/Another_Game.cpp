#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;   
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ok |= (x & 1);
    }
    cout << (ok ? "first" : "second") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}