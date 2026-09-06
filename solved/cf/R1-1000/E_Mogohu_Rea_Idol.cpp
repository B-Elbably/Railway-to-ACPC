#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
const T EPS = 1e-12;

struct pt {
    int x,y;
    pt(){}
    pt(int _x,int _y):x(_x),y(_y){}
    pt operator+(const pt& p) const {
        return pt(x+p.x,y+p.y);
    }
    pt operator-(const pt& p) const {
        return pt(x-p.x,y-p.y);
    }
    bool operator==(const pt& p) const {
        return x==p.x&&y==p.y;
    }
};

T cross(const pt& a,const pt& b) {
    return (T)a.x*b.y-(T)a.y*b.x;
}

T dot(const pt& a,const pt& b) {
    return (T)a.x*b.x+(T)a.y*b.y;
}

T orient(const pt& a,const pt& b,const pt& c) {
    return cross(b-a,c-a);
}

void reorder(vector<pt>& p) {
    if(p.empty()) return;
    int pos=0;
    for(int i=1;i<(int)p.size();i++) {
        if(p[i].y<p[pos].y||(p[i].y==p[pos].y&&p[i].x<p[pos].x))
            pos=i;
    }
    rotate(p.begin(),p.begin()+pos,p.end());
}

vector<pt> minkowskiSum(vector<pt> a,vector<pt> b) {
    if(a.empty()||b.empty()) return {};
    reorder(a);
    reorder(b);
    int n=a.size(),m=b.size();
    a.push_back(a[0]);
    b.push_back(b[0]);
    vector<pt> res;
    int i=0,j=0;
    while(i<n||j<m) {
        res.push_back(a[i]+b[j]);
        pt edgeA,edgeB;
        if(i<n) edgeA=a[i+1]-a[i];
        if(j<m) edgeB=b[j+1]-b[j];
        if(i==n) j++;
        else if(j==m) i++;
        else {
            T cr=cross(edgeA,edgeB);
            if(fabsl(cr)<=EPS) i++,j++;
            else if(cr>0) i++;
            else j++;
        }
    }
    vector<pt> clean;
    for(auto p:res) {
        while(clean.size()>=2) {
            int sz=clean.size();
            if(orient(clean[sz-2],clean[sz-1],p)==0)
                clean.pop_back();
            else break;
        }
        clean.push_back(p);
    }
    while(clean.size()>=3&&orient(clean[clean.size()-2],clean.back(),clean[0])==0)
        clean.pop_back();
    while(clean.size()>=3&&orient(clean.back(),clean[0],clean[1])==0)
        clean.erase(clean.begin());
    return clean;
}

bool inConvexPolygonLogN(const vector<pt>& p,pt a,bool strict=true) {
    int n=p.size();
    if(n<3) return false;
    T c1=orient(p[0],p[1],a);
    T c2=orient(p[0],p[n-1],a);
    if(strict) {
        if(c1<=EPS||c2>=-EPS) return false;
    } else {
        if(c1<-EPS||c2>EPS) return false;
    }
    int l=1,r=n-1;
    while(r-l>1) {
        int mid=(l+r)/2;
        if(orient(p[0],p[mid],a)>=0) l=mid;
        else r=mid;
    }
    T c3=orient(p[l],p[r],a);
    return strict?c3>EPS:c3>=-EPS;
}

void solve() {
    int n0;
    cin>>n0;
    vector<pt> poly1(n0);
    for(auto& p:poly1) cin>>p.x>>p.y;

    int n1;
    cin>>n1;
    vector<pt> poly2(n1);
    for(auto& p:poly2) cin>>p.x>>p.y;

    int n2;
    cin>>n2;
    vector<pt> poly3(n2);
    for(auto& p:poly3) cin>>p.x>>p.y;

    vector<pt> poly = minkowskiSum(poly1, minkowskiSum(poly2, poly3));
    int q; cin >> q;
    while (q--) {
        pt xx; cin >> xx.x >> xx.y;
        xx.x *= 3; xx.y *= 3;
        cout << (inConvexPolygonLogN(poly, xx, false) ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}