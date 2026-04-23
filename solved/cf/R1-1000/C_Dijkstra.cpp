#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
 
const ll N = 2e5 + 5, inf = LLONG_MAX;
ll dist[N];
map<ll, vector<pair<ll, ll>>> adj;
priority_queue<pair<ll, ll>> pq;  
vector<int> p(N, -1);
void dijkstra(ll start) {
 
    fill(dist, dist + N, inf);
    dist[start] = 0;
    pq.push({0, start});
 
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll c = -pq.top().first;  
        pq.pop();
        
 
        if (c != dist[u])
            continue;
        
 
        for (auto &edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                p[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    for (ll i = 0; i < m; i++) {
        ll c, u, v;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
     }
    dijkstra(1);
    
    // for (int i = 1; i <= n; i++) {
    //     cout << dist[i] << " ";
    // }
    if (dist[n] == inf) {
        cout << -1;
        return;
    }
    vector<ll> path;
    for (ll v = n; v != -1; v = p[v]) path.push_back(v);
    reverse(all(path));
    for (auto &x : path) cout << x << " ";
    // cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
 
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}