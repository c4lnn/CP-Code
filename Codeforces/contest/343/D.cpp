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
const int N=5e5+5;
int sz[N],dfn[N],top[N],son[N],fa[N],cnt,ls[N<<2],rs[N<<2],w[N<<2];
VI g[N];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=-1;
}
void push_down(int p) {
    if(w[p]!=-1) {
        w[p<<1]=w[p<<1|1]=w[p];
        w[p]=-1;
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        w[p]=v;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
}
int query(int p,int x) {
    if(ls[p]==rs[p]) return w[p];
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) return query(p<<1,x);
    return query(p<<1|1,x);
}
void dfs1(int u) {
    sz[u]=1;
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
    for(auto v:g[u]) if(!top[v]) {
        dfs2(v,v);
    }
}
void fill(int u) {
    update(1,dfn[u],dfn[u]+sz[u]-1,1);
}
void clear(int u) {
    while(u) {
        update(1,dfn[top[u]],dfn[u],0);
        u=fa[top[u]];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v),g[v].PB(u);
    }
    build(1,1,n);
    dfs1(1);
    dfs2(1,1);
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int o,u;cin>>o>>u;
        if(o==1) fill(u);
        else if(o==2) clear(u);
        else cout<<query(1,dfn[u])<<'\n';
    }
    return 0;
}