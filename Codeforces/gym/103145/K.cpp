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
const int N=2e5+5;
int fa[N],sz[N];
LL res[N];
struct E {
    int u,v,w,f;
    E() {}
    E(int u,int v,int w,int f):u(u),v(v),w(w),f(f) {}
    bool operator < (const E &T) const {
        return w>T.w||w==T.w&&f<T.f;
    }
};
vector<E> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m,q;cin>>n>>m>>q;
        e.clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;cin>>u>>v>>w;
            e.EB(u,v,w,0);
        }
        for(int i=1;i<=q;i++) {
            int x;cin>>x;
            e.EB(0,0,x,i);
        }
        sort(ALL(e));
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        LL sum=0;
        for(auto x:e) {
            if(x.f) res[x.f]=sum;
            else {
                int fu=find(x.u),fv=find(x.v);
                if(fu==fv) continue;
                sum-=1ll*sz[fu]*(sz[fu]-1)/2;
                sum-=1ll*sz[fv]*(sz[fv]-1)/2;
                sz[fv]+=sz[fu];
                fa[fu]=fv;
                sum+=1ll*sz[fv]*(sz[fv]-1)/2;
            }
        }
        for(int i=1;i<=q;i++) cout<<res[i]<<'\n';
    }
    return 0;
}