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
const int N=1e5+5;
int fa[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &a) const {
        return w<a.w;
    }
};
vector<E> e;
map<int,int> mp;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m,k;cin>>n>>m>>k;
        e.clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;cin>>u>>v>>w;
            e.EB(u,v,w);
        }
        sort(ALL(e));
        if(k==n) {
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++) fa[i]=i;
        int tot=n;
        mp.clear();
        for(auto x:e) {
            int fu=find(x.u),fv=find(x.v);
            if(fu!=fv) {
                fa[fu]=fv;
                --tot;
            }
            mp[x.w]=tot;
        }
        int res=-1;
        for(auto x:mp) if(x.SE==k) {
            res=x.FI;
            break;
        }
        cout<<res<<'\n';
    }
    return 0;
}