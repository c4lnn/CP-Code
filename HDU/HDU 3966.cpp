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
int n,m,q;
int cnt,sz[N],son[N],fa[N],top[N],dfn[N],dep[N],id[N];
int a[N],ls[N<<2],rs[N<<2],add[N<<2];
VI g[N];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {add[p]=a[id[l]];return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    add[p]=0;
}
void push_down(int p) {
    if(add[p]) {
        add[p<<1]+=add[p],add[p<<1|1]+=add[p];
        add[p]=0;
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {add[p]+=v;return;}
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
}
int query(int p,int x) {
    if(ls[p]==rs[p]) return add[p];
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) return query(p<<1,x);
    return query(p<<1|1,x);
}
void dfs1(int u) {
    sz[u]=1;
    for(auto v:g[u]) if(v!=fa[u]) {
        dep[v]=dep[u]+1;
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
void upd(int a,int b,int v) {
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) {
            update(1,dfn[top[a]],dfn[a],v);
            a=fa[top[a]];

        }
        else {
            update(1,dfn[top[b]],dfn[b],v);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) update(1,dfn[b],dfn[a],v);
    else update(1,dfn[a],dfn[b],v);
}
int main() {
    while(~scanf("%d%d%d",&n,&m,&q)) {
        for(int i=1;i<=n;i++) {
            g[i].clear();
            son[i]=0;
        }
        cnt=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) {
            int u,v;scanf("%d%d",&u,&v);
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        for(int i=1;i<=q;i++) {
            char o;scanf(" %c",&o);
            if(o=='I') {
                int a,b,v;scanf("%d%d%d",&a,&b,&v);
                upd(a,b,v);
            }
            else if(o=='D') {
                int a,b,v;scanf("%d%d%d",&a,&b,&v);
                upd(a,b,-v);
            }
            else {
                int x;scanf("%d",&x);
                printf("%d\n",query(1,dfn[x]));
            }
        }
    }
    return 0;
}