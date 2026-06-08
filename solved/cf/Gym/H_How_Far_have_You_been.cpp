#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
map<int, string> mp = {
    {1, "Alas! Farha is bitten by snake. She is now at 75."},
    {4, "Alas! Farha is bitten by snake. She is now at 79."},
    {5, "Farha is on ladder."},
    {6, "Yay! Farha has won the game. She is now at 100."},
    {2, "Nothing happened to her."},
    {3, "Nothing happened to her."}
};
void solve() {
    int n;
    cin >> n;
    cout << mp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
