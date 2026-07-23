#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


const int N = 505; 
char grid[N][N] , grid1[N][N];

int dist[N][N];
int dist1[N][N];
int dist2[N][N];

int ans[2] = {0 , 0};

int n , m; 


int xs[4] = {1 , -1 , 0 , 0};
int ys[4] = {0 , 0 , -1 , 1};

bool valid(int r , int c){
    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '#') return false;
    return true;
}


bool valid1(int r , int c){
    if (r < 0 || c < 0 || r >= n || c >= m || grid1[r][c] == '#') return false;
    return true;
}

void solve() {
    memset(dist , -1 , sizeof dist);
    memset(dist1 , -1 , sizeof dist1);
    memset(dist2 , -1 , sizeof dist2);

    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }




    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid1[i][j];
        }
    }
    dist[0][0] = 0; 

    queue<pair<int , int>> q; 
    q.push({0 , 0});

    while (!q.empty())
    {
        auto [r , c] = q.front(); 
        q.pop(); 

        for(int i = 0 ; i < 4 ; i++){
            int nx = r + xs[i];
            int ny = c + ys[i];

            if (valid(nx , ny)){
                if (dist[nx][ny] == -1){
                    dist[nx][ny] = dist[r][c] + 1; 
                    q.push({nx , ny});
                }
            }
        }
    }

    if (dist[n - 1][m - 1] == -1){
        cout << "NO\n";
        return ; 
    }
    ans[0] = dist[n - 1][m - 1];

    dist1[0][0] = 0; 
    queue<pair<int , int>> qs; 
    qs.push({0 , 0});

    while (!qs.empty())
    {
        auto [r , c] = qs.front(); 
        qs.pop(); 

        for(int i = 0 ; i < 4 ; i++){
            int nx = r + xs[i];
            int ny = c + ys[i];

            if (valid1(nx , ny)){
                if (dist1[nx][ny] == -1){
                    dist1[nx][ny] = dist1[r][c] + 1; 
                    qs.push({nx , ny});
                }
            }
        }
    }

    if (dist1[n - 1][m - 1] == -1){
        cout << "NO\n";
        return ; 
    }
    ans[1] = dist1[n - 1][m - 1];

    if (ans[0] != ans[1]){
        cout << "NO\n";
        return; 
    }


    dist2[0][0] = 0; 
    queue<pair<int , int>> qss;

    qss.push({0 , 0});

    while (!qss.empty())
    {
        auto [r , c] = qss.front();
        qss.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = r + xs[i];
            int ny = c + ys[i];

            if (valid(nx , ny) && valid1(nx , ny)){
                if (dist2[nx][ny] == -1){
                    dist2[nx][ny] = dist2[r][c] + 1;
                    qss.push({nx , ny}); 
                }
            }
        }
    }
    

    if (dist2[n - 1][m-1] == -1){
        cout << "NO\n";
        return ; 
    }


    if (dist2[n - 1][m - 1] == ans[1]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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
