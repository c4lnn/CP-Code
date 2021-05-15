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
int cnt,fa[N],dep[N],sz[N],top[N],son[N],dfn[N],id[N],res[N];
int ls[N<<2],rs[N<<2],tot[N<<2],mx[N<<2];
VI g[N];
VPII o[N];
void init(int n) {
    for(int i=1;i<=n;i++) {
        son[i]=0;
        g[i].clear();
        o[i].clear();
    }
    cnt=0;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        tot[p]=0;
        mx[p]=l;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tot[p]=0;
    mx[p]=mx[p<<1];
}
void update(int p,int x,int v) {
    if(ls[p]==rs[p]) {tot[p]+=v;return;}
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    if(tot[p<<1]>=tot[p<<1|1]) {
        tot[p]=tot[p<<1];
        mx[p]=mx[p<<1];
    }
    else {
        tot[p]=tot[p<<1|1];
        mx[p]=mx[p<<1|1];
    }
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
    id[cnt]=u;
    if(son[u]) dfs2(son[u],t);
    for(auto v:g[u]) if(v!=fa[u]&&v!=son[u]) {
        dfs2(v,v);
    }
}
void solve(int a,int b,int c) {
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) {
            o[dfn[top[a]]].EB(c,1);
            o[dfn[a]+1].EB(c,-1);
            a=fa[top[a]];
        }
        else {
            o[dfn[top[b]]].EB(c,1);
            o[dfn[b]+1].EB(c,-1);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) {
        o[dfn[b]].EB(c,1);
        o[dfn[a]+1].EB(c,-1);
    }
    else {
        o[dfn[a]].EB(c,1);
        o[dfn[b]+1].EB(c,-1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m) {
        if(!n&&!m) break;
        init(n);
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,0,100000);
        for(int i=1;i<=m;i++) {
            int x,y,z;cin>>x>>y>>z;
            solve(x,y,z);
        }
        for(int i=1;i<=n;i++) {
            for(auto x:o[i]) update(1,x.FI,x.SE);
            res[id[i]]=mx[1];
        }
        for(int i=1;i<=n;i++) cout<<res[i]<<'\n';
    }
    return 0;
}