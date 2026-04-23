#include <bits/stdc++.h>
using namespace std;

int get_val(char c) {
    if (isdigit(c)) return c - '0';
    if (isupper(c)) return c - 'A' + 10;
    return c - 'a' + 36;
}

char get_char(int v) {
    if (v < 10) return v + '0';
    if (v < 36) return v - 10 + 'A';
    return v - 36 + 'a';
}

const int N = 4e3 + 5;
vector<int> adj[N];
int in[N], out[N];
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int u = get_val(s[0]) * 62 + get_val(s[1]);
        int v = get_val(s[1]) * 62 + get_val(s[2]);
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    int start = -1, end = -1;
    bool ok = true;
    int out_ = 0, in_ = 0;

    for (int i = 0; i < N; i++) {
        if (abs(out[i] - in[i]) > 1) ok = false;
        if (out[i] - in[i] == 1) {
            out_++;
            start = i;
        } else if (in[i] - out[i] == 1) {
            in_++;
            end = i;
        }
    }

    if (out_ > 1 || in_ > 1) ok = false;
    if (start == -1) {
        for (int i = 0; i < N; i++) {
            if (out[i]) {
                start = i;
                break;
            }
        }
    }
    if (start != -1) dfs(start);
    if (!ok || (int)path.size() != n + 1) {
        cout << "NO" << endl;
        return;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;

    vector<char> res;
    res.push_back(get_char(path[0] / 62));
    for (int i = 0; i < (int)path.size(); i++) {
        res.push_back(get_char(path[i] % 62));
    }
    for(char c : res) cout << c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}