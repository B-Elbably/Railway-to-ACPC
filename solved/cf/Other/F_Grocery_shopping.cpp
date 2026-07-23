#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 18;
vector<int> arr[N];
queue<int> que[N];
bool vis[1 << N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (auto &x : t) cin >> x;
    vector<int> freq(n);
    for (int i = 0; i < m; ++i) {
        int si, ui;
        cin >> si >> ui;
        arr[--si].push_back(ui);
    }
    for (int i = 0; i < n; ++i) {
        sort(all(arr[i]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [time, mask] = pq.top();
        pq.pop();
        if (vis[mask]) continue;
        vis[mask] = true;
        if (mask == (1 << n) - 1) {
            cout << time << endl;
            return;
        }
        for(int i = 0; i < n; i++){
            if((1 << i) & mask) continue;
            while(freq[i] < arr[i].size() && arr[i][freq[i]] <= time){
                int now = 0;
                if(que[i].size()) now = que[i].back();
                int start = max(0 + arr[i][freq[i]], now);
                int end = start + t[i];
                que[i].push(end);
                freq[i]++;
            }
            while(que[i].size() && que[i].front() <= time) que[i].pop();
            int add = 0;
            if(que[i].size()) add = que[i].back() - time;
            pq.push(make_pair(time + add + t[i], mask | (1 << i)));
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
