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
const int N=1e4+5;
int dep[N],fa[N],f[N][15],mn[N][15],rt[N],lim=14;
VPII g[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &T) const {
        return w>T.w;
    }
};
vector<E> e;
void kruskal(int n) {
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(ALL(e));
    for(auto x:e) {
        int fu=find(x.u),fv=find(x.v);
        if(fu==fv) continue;
        fa[fu]=fv;
        g[x.u].EB(x.v,x.w);
        g[x.v].EB(x.u,x.w);
    }
}
void dfs(int u) {
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(dep[v]) continue;
        dep[v]=dep[u]+1;
        f[v][0]=u;
        mn[v][0]=w;
        for(int i=1;i<=lim;i++) {
            f[v][i]=f[f[v][i-1]][i-1];
            mn[v][i]=min(mn[v][i-1],mn[f[v][i-1]][i-1]);
        }
        dfs(v);
    }
}
int solve(int a,int b) {
    if(dep[a]>dep[b]) swap(a,b);
    int ret=INT_MAX;
    for(int i=lim;~i;i--) if(dep[f[b][i]]>=dep[a]) {
        ret=min(ret,mn[b][i]);
        b=f[b][i];
    }
    if(a==b) return ret;
    for(int i=lim;~i;i--) if(f[a][i]!=f[b][i]) {
        ret=min({ret,mn[a][i],mn[b][i]});
        a=f[a][i],b=f[b][i];
    }
    return ret=min({ret,mn[a][0],mn[b][0]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        e.EB(u,v,w);
    }
    kruskal(n);
    for(int i=1;i<=n;i++) if(!dep[i]) {
        dep[i]=1;
        dfs(i);
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int a,b;cin>>a>>b;
        if(find(a)!=find(b)) cout<<-1<<'\n';
        else cout<<solve(a,b)<<'\n';
    }
    return 0;
}