#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    VPII b(m);
    for(int i=0;i<m;i++) cin>>b[i].FI>>b[i].SE;
    sort(ALL(b));
    vector<VI> a(m+1);
    int cnt=0;
    unordered_map<int,int> mp;
    for(auto x:b) {
        if(!mp.count(x.FI)) mp[x.FI]=++cnt;
        a[mp[x.FI]].PB(x.SE);
    }
    VI t1,t2;
    unordered_map<int,bool> vis;
    vis[n]=true;
    for(int i=1;i<=cnt;i++) {
        for(auto y:a[i]) {
            if(y>=1&&vis.count(y-1)&&vis[y-1]==true||y<2*n&&vis.count(y+1)&&vis[y+1]==true) t1.PB(y);
            else t2.PB(y);
        }
        for(auto y:t1) vis[y]=true;
        for(auto y:t2) vis[y]=false;
        t1.clear(),t2.clear();
    }
    int res=SZ(vis);
    for(auto y:vis) if(y.SE==false) --res;
    cout<<res<<'\n';
    return 0;
}