#include<iostream>
using namespace std;
int n,r,cnt=999999;
char res[1000003], ans[1000003];

void solve(int a,int b){
    int now = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a && b && now < cnt){
            if(a >= b)
                res[i] = 'T', a -= b;
            else 
                res[i] = 'B', b -= a;
            now += (res[i] == res[i+1]);
        }
        else
            return;
    }
    if(!a && b==1 && res[0] == 'T'){
        cnt = now; 
        for(int i = 0; i < n; i++)
            ans[i] = res[i];
    }
}

int main(){
    cin >> n >> r;
    for(int i = 1; i <= r; i++)
        solve(r, i), solve(i, r);
    if(cnt != 999999)
        cout << cnt << endl << ans;
    else 
        cout << "IMPOSSIBLE";
}