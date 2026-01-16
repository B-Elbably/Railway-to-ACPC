#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string g;
int b,c;

bool match(string candy) {
    int candy_b = 0, candy_c = 0;
    for (int i = 0; i < 4;++i) 
        candy_b += (candy[i] == g[i]);
    
    for (int i = 0; i < 4;++i) 
        for (int j = 0; j < 4;++j) 
            candy_c += (i != j && candy[i] == g[j]);
        
    return (candy_b == b && candy_c == c);
}

void solve() {
    int n;
    cin >> n;
    set<string> st;
    for (int i = 123; i <= 9999 ; ++i) {
        string s = to_string(i);
        set<char> used;
        if (s.length() == 3) s = "0" + s;
        for (char ch : s) used.insert(ch);
        if (used.size() == 4) st.insert(s);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> g >> b >> c;
        vector<string> toKeep;
        for (auto candy : st) 
            if (match(candy)) 
                toKeep.push_back(candy);
        st.clear();
        for (auto candy : toKeep) 
            st.insert(candy);
        
    }
    if (st.size() == 0) cout << "Incorrect data" << endl;
    else if (st.size() == 1) cout << *st.begin() << endl;
    else cout << "Need more data" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
