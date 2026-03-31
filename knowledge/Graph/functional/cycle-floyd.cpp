#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<vector<int>> adj;

void find_cycle(int start) {
    int slow = adj[start][0];
    int fast = adj[adj[start][0]][0];

    while (slow != fast) {
        slow = adj[slow][0];
        fast = adj[adj[fast][0]][0];
    }

    slow = start;
    while (slow != fast) {
        slow = adj[slow][0];
        fast = adj[fast][0];
    }
    
    int first = slow;

    fast = adj[slow][0];
    int length = 1;
    while (slow != fast) {
        fast = adj[fast][0];
        length++;
    }

    cout << first << " " << length << endl;
}

void solve() {
    int n;
    cin >> n;
    
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        adj[i].push_back(v);
    }

    find_cycle(0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}