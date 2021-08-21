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
int son[N],sz[N],dep[N],dfn[N],fa[N],top[N],cnt,ls[N<<2],rs[N<<2];
LL w[3][N<<2],laz[3][N<<2];
VI g[N];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p) {
    for(int i=0;i<3;i++) if(laz[i][p]) {
        w[i][p<<1]+=laz[i][p],w[i][p<<1|1]+=laz[i][p];
        laz[i][p<<1]+=laz[i][p],laz[i][p<<1|1]+=laz[i][p];
        laz[i][p]=0;
    }
}
void update(int p,int l,int r,LL v) {
    if(ls[p]>=l&&rs[p]<=r) {
        w[0][p]++,w[1][p]+=v,w[2][p]+=v*v;
        laz[0][p]++,laz[1][p]+=v,laz[2][p]+=v*v;
        return;
    }
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
}
LL query(int p,int x) {
    if(ls[p]==rs[p]) return w[0][p]*ls[p]*ls[p]-2*w[1][p]*ls[p]+w[2][p];
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) return query(p<<1,x);
    return query(p<<1|1,x);
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
    for(auto v:g[u]) if(!top[v]) dfs2(v,v);
}
void solve(int a,int b) {
    VPII o1,o2;
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) {
            o1.EB(dfn[top[a]],dfn[a]);
            a=fa[top[a]];
        }
        else {
            o2.EB(dfn[top[b]],dfn[b]);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) o1.EB(dfn[b],dfn[a]);
    else o2.EB(dfn[a],dfn[b]);
    int len=0;
    for(auto x:o1) {
        update(1,x.FI,x.SE,x.SE+len+1);
        len+=x.SE-x.FI+1;
    }
    reverse(ALL(o2));
    for(auto x:o2) {
        update(1,x.FI,x.SE,x.FI-len-1);
        len+=x.SE-x.FI+1;
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
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int o;cin>>o;
        if(o==1) {
            int a,b;cin>>a>>b;
            solve(a,b);
        }
        else {
            int x;cin>>x;
            cout<<query(1,dfn[x])<<'\n';
        }
    }
    return 0;
}