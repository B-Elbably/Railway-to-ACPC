#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


int n; 
int k;  


void solve() {
    cin >> n; 
  
    int mp[n + 1];
    int tmp; 
    for(int i = 0 ; i < n ; i++){
        cin >> tmp; 
        mp[tmp - 1] = i;
    }
    set<pair<int , int>> ind[n];
    cin >> k;
    int ls[k][n];
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < n ; j++){ 
            cin >> ls[i][j];
            ind[j].insert({i , j});
        }
    }


    vector<int> visit(n , 0);
  

    int ns; 
    cin >> ns;
    deque<pair<int , int>> q; 
    for(int i = 0 ; i < k ; i++){
        q.push_back({i , 0});
        visit[ls[i][0] - 1] = 1; 
        if (ls[i][0] - 1 == mp[ns - 1]){
            cout << "YES";
            return ; 
        }
    }
    

    while (!q.empty())
    {
        auto [r , c] = q.front();
        q.pop_front(); 
        visit[ls[r][c] - 1] = 1; 
        if ((ls[r][c] - 1) == mp[ns - 1]){
            cout << "YES";
            return;
        }
        vector<pair<int , int>> tmps; 
        for(auto [nr , nc] : ind[ls[r][c] - 1]){
            q.push_back({nr , nc});
            tmps.push_back({nr , nc});
        }

        for(auto [rr , cc] : tmps){
            ind[ls[r][c] - 1].erase({rr , cc});
        }



    }

    if (visit[mp[ns - 1]]){
        cout << "YES";
    }
    else{
        cout << "NO";
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
