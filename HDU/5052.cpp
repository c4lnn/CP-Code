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
const int N=5e4+5;
int cnt,dfn[N],fa[N],sz[N],son[N],top[N],dep[N],a[N],id[N];
int ls[N<<2],rs[N<<2],add[N<<2];
VI g[N];
struct Node {
    int mx,mn,up_mx,down_mx;
}node[N<<2];
void init(int n) {
    for(int i=1;i<=n;i++) {
        son[i]=0;
        g[i].clear();
    }
    cnt=0;
}
void push_up(int p) {
    node[p].mx=max(node[p<<1].mx,node[p<<1|1].mx);
    node[p].mn=min(node[p<<1].mn,node[p<<1|1].mn);
    node[p].up_mx=max({node[p<<1].up_mx,node[p<<1|1].up_mx,node[p<<1].mx-node[p<<1|1].mn});
    node[p].down_mx=max({node[p<<1].down_mx,node[p<<1|1].down_mx,node[p<<1|1].mx-node[p<<1].mn});
}
void push_down(int p) {
    if(add[p]) {
        node[p<<1].mx+=add[p],node[p<<1].mn+=add[p];
        node[p<<1|1].mx+=add[p],node[p<<1|1].mn+=add[p];
        add[p<<1]+=add[p],add[p<<1|1]+=add[p];
        add[p]=0;
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        node[p].mx=node[p].mn=a[id[l]];
        node[p].up_mx=node[p].down_mx=add[p]=0;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
    add[p]=0;
}
void update(int p,int l,int r,int x) {
    if(ls[p]>=l&&rs[p]<=r) {
        node[p].mx+=x;
        node[p].mn+=x;
        add[p]+=x;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,x);
    if(r>mid) update(p<<1|1,l,r,x);
    push_up(p);
}
Node query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return node[p];
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    auto ret=query(p<<1,l,r);
    auto t=query(p<<1|1,l,r);
    ret.up_mx=max({ret.up_mx,t.up_mx,ret.mx-t.mn});
    ret.down_mx=max({ret.down_mx,t.down_mx,t.mx-ret.mn});
    ret.mx=max(ret.mx,t.mx);
    ret.mn=min(ret.mn,t.mn);
    return ret;
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
int solve(int a,int b,int v) {
    int mx=0,mn=0x3f3f3f3f,up_mx=0,down_mx=0;
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) {
            auto t=query(1,dfn[top[a]],dfn[a]);
            update(1,dfn[top[a]],dfn[a],v);
            up_mx=max({up_mx,t.up_mx,t.mx-mn});
            mn=min(mn,t.mn);
            a=fa[top[a]];
        }
        else {
            auto t=query(1,dfn[top[b]],dfn[b]);
            update(1,dfn[top[b]],dfn[b],v);
            down_mx=max({down_mx,t.down_mx,mx-t.mn});
            mx=max(mx,t.mx);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) {
        auto t=query(1,dfn[b],dfn[a]);
        update(1,dfn[b],dfn[a],v);
        up_mx=max({up_mx,t.up_mx,t.mx-mn});
        mn=min(mn,t.mn);
    }
    else {
        auto t=query(1,dfn[a],dfn[b]);
        update(1,dfn[a],dfn[b],v);
        down_mx=max({down_mx,t.down_mx,mx-t.mn});
        mx=max(mx,t.mx);
    }
    return max({up_mx,down_mx,mx-mn});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        init(n);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v),g[v].PB(u);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        int q;cin>>q;
        for(int i=1;i<=q;i++) {
            int a,b,v;cin>>a>>b>>v;
            cout<<solve(a,b,v)<<'\n';
        }
    }
    return 0;
}