#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    vector<string> board(3);
    for (auto &row : board) cin >> row;
    set<char> s;
    set<char> win_1;
    set<pair<char, char>> win_2;
    // rows
    for (int i = 0; i < 3; ++i){
        s.clear();
        for (int j = 0; j < 3; ++j){
            s.insert(board[i][j]);
        }
        if (s.size() == 1) {
            win_1.insert(*s.begin());
        }else if (s.size() == 2) {
            char first = *s.begin();
            char second = *(++s.begin());
            if (first > second) swap(first, second);
            win_2.insert({first, second});
        }
    } 
    // columns
    for (int i = 0; i < 3; ++i){
        s.clear();
        for (int j = 0; j < 3; ++j){
            s.insert(board[j][i]);
        }
        if (s.size() == 1) {
            win_1.insert(*s.begin());
        }else if (s.size() == 2) {
            char first = *s.begin();
            char second = *(++s.begin());
            if (first > second) swap(first, second);
            win_2.insert({first, second});
        }
    } 
    // main diagonal
    s.clear();
    for (int i = 0; i < 3; ++i){
        s.insert(board[i][i]);
    }
    if (s.size() == 1) {
            win_1.insert(*s.begin());
        }else if (s.size() == 2) {
            char first = *s.begin();
            char second = *(++s.begin());
            if (first > second) swap(first, second);
            win_2.insert({first, second});
        }
    s.clear();
    // anti diagonal
    for (int i = 0; i < 3; ++i){
        s.insert(board[i][2 - i]);
    }
    if (s.size() == 1) {
            win_1.insert(*s.begin());
        }else if (s.size() == 2) {
            char first = *s.begin();
            char second = *(++s.begin());
            if (first > second) swap(first, second);
            win_2.insert({first, second});
        }
    cout << (int)win_1.size() << '\n' << (int)win_2.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
