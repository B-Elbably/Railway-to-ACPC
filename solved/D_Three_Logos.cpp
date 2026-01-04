#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point { int x, y; };

void fillRect(vector<string> &grid, int row, int col, Point p, char c) {
    for (int i = 0; i < p.y; i++)
        for (int j = 0; j < p.x; j++)
            grid[row + i][col + j] = c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Point> points(3);
    vector<char> id = {'A','B','C'};
    for(int i=0;i<3;i++) 
        cin >> points[i].x >> points[i].y;

    int area = points[0].x*points[0].y + points[1].x*points[1].y + points[2].x*points[2].y;
    int n = 1;
    while(n*n < area) n++;
    if(n*n != area) { cout << -1; return 0; }

    vector<vector<int>> perms = {
        {0,1,2}, {0,2,1}, {1,0,2},
        {2,1,0}, {1,2,0}, {2,0,1}
    };

    for(auto &perm : perms){
        for(int mask=0; mask<8; mask++){
            vector<Point> p(3);
            for(int i=0;i<3;i++){
                p[i] = points[perm[i]];
                if(mask & (1<<i)) swap(p[i].x, p[i].y);
            }

            Point A = p[0], B = p[1], C = p[2];
            vector<string> grid(n,string(n,'.'));

            if(A.y == n && B.y == n && C.y == n && A.x + B.x + C.x == n){
                fillRect(grid,0,0,A,id[perm[0]]);
                fillRect(grid,0,A.x,B,id[perm[1]]);
                fillRect(grid,0,A.x+B.x,C,id[perm[2]]);
                cout << n << '\n';
                for(auto &row:grid) cout << row << '\n';
                return 0;
            }

            if(A.x == n && B.y == C.y && B.x + C.x == n && A.y + B.y == n){
                fillRect(grid,0,0,A,id[perm[0]]);
                fillRect(grid,A.y,0,B,id[perm[1]]);
                fillRect(grid,A.y,B.x,C,id[perm[2]]);
                cout << n << '\n';
                for(auto &row:grid) cout << row << '\n';
                return 0;
            }
        }
    }

    cout << -1;
}
