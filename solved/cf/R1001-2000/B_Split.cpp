//  Tutorail approach
#include <bits/stdc++.h>
using namespace std;


#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    map<int, int> freq;
    for (auto &x : a){cin >> x; freq[x]++;}
    int odd = 0, fours = 0, even = 0;
    for (auto [k, v] : freq) {
        if (v & 1) odd++;
        else if (v % 4) even++;
        else fours++;
    }
    if ((fours & 1) && (odd == 0)) odd -= 2;
    cout << odd + 2 * (fours + even) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
