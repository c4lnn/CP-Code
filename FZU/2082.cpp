#include <iostream>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=5e4+5;
int cnt,n,m,w[N],b[N],c[N],son[N],sonn[N],sz[N],fa[N],dep[N],dfn[N],top[N];
LL a[N];
VPII g[N];
void init() {
    cnt=0;
    for(int i=1;i<=n;i++) a[i]=son[i]=0,g[i].clear();
}
int lowbit(int x) {
    return x&-x;
}
void update(int x,int v) {
    for(int i=x;i<=cnt;i+=lowbit(i)) a[i]+=v;
}
LL query(int x) {
    LL ret=0;
    for(int i=x;i;i-=lowbit(i)) ret+=a[i];
    return ret;
}
void dfs1(int u) {
    sz[u]=1;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI;
        if(v==fa[u]) continue;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v,sonn[u]=g[u][i].SE;
    }
}
void dfs2(int u,int t,int i) {
    top[u]=t;
    dfn[u]=++cnt;
    b[cnt]=i;
    c[i]=cnt;
    if(son[u]) dfs2(son[u],t,sonn[u]);
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v,g[u][i].SE);
    }
}
LL solve(int x,int y) {
    LL ret=0;
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) {
            ret+=query(dfn[x])-query(dfn[top[x]]);
            ret+=w[b[dfn[top[x]]]];
            x=fa[top[x]];
        }
        else {
            ret+=query(dfn[y])-query(dfn[top[y]]);
            ret+=w[b[dfn[top[y]]]];
            y=fa[top[y]];
        }
    }
    if(dep[x]>dep[y]) swap(x,y);
    return ret+query(dfn[y])-query(dfn[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m) {
        init();
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v>>w[i];
            g[u].PB(MP(v,i));
            g[v].PB(MP(u,i));
        }
        dfs1(1);
        dfs2(1,1,0);
        for(int i=2;i<=cnt;i++) update(i,w[b[i]]);
        for(int i=1;i<=m;i++) {
            int o,u,v;cin>>o>>u>>v;
            if(!o) update(c[u],v-w[u]),w[u]=v;
            else cout<<solve(u,v)<<'\n';
        }
    }
    return 0;
}