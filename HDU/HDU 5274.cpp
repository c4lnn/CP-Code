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
int cnt,sz[N],son[N],fa[N],top[N],dfn[N],dep[N];
int a[N],w[N<<2],ls[N<<2],rs[N<<2];
VI g[N];
void init(int n) {
    for(int i=1;i<=n;i++) son[i]=0,g[i].clear();
    cnt=0;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {w[p]=a[l];return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=w[p<<1]^w[p<<1|1];
}
void update(int p,int x,int v) {
    if(ls[p]==rs[p]) {
        w[p]=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    w[p]=w[p<<1]^w[p<<1|1];
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return w[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)^query(p<<1|1,l,r);
}
void dfs1(int u) {
    sz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for(auto v:g[u]) if(v!=fa[u]) {
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    dfn[u]=++cnt;
    if(son[u]) dfs2(son[u],t);
    for(auto v:g[u]) if(v!=fa[u]&&v!=son[u]) {
        dfs2(v,v);
    }
}
int solve(int a,int b) {
    int ret=0;
    while(top[a]!=top[b]) {
        if(dep[a]>dep[b]) {
            ret^=query(1,dfn[top[a]],dfn[a]);
            a=fa[top[a]];
        }
        else {
            ret^=query(1,dfn[top[b]],dfn[b]);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) ret^=query(1,dfn[b],dfn[a]);
    else ret^=query(1,dfn[a],dfn[b]);
    return ret-1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,q;cin>>n>>q;
        init(n);
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs1(1);
        dfs2(1,1);
        for(int i=1;i<=n;i++) cin>>a[dfn[i]],++a[dfn[i]];
        build(1,1,n);
        for(int i=1;i<=q;i++) {
            int o,x,y;cin>>o>>x>>y;
            if(!o) update(1,dfn[x],y+1);
            else cout<<solve(x,y)<<'\n';
        }
    }
    return 0;
}