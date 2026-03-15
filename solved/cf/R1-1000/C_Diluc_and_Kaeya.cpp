#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<pair<int, int>, int> freq;
    int d = 0, k = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') d++;
        else k++;
        int g = std::gcd(d, k);
        freq[{d / g, k / g}]++;
        cout << freq[{d / g, k / g}] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}