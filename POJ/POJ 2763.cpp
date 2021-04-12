#include <cstdio>
#include <vector>
#define SZ(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
// head
const int N=1e5+5;
int n,q,s,a[N];
int cnt,sz[N],fa[N],dfn[N],top[N],son[N],sonn[N],id[N],idd[N],dep[N];
int ls[N<<2],rs[N<<2],w[N<<2];
int tot,head[N],to[N<<1],e[N<<1],nxt[N<<1];
void add_edge(int u,int v,int i) {
    nxt[++tot]=head[u];
    to[tot]=v;
    e[tot]=i;
    head[u]=tot;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        w[p]=a[idd[l]];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=w[p<<1]+w[p<<1|1];
}
void update(int p,int x,int v) {
    if(ls[p]==rs[p]) {
        w[p]=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    w[p]=w[p<<1]+w[p<<1|1];
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return w[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    else if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
void dfs1(int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[v]+=sz[u];
        if(sz[v]>sz[son[u]]) son[u]=v,sonn[u]=e[i];
    }
}
void dfs2(int u,int t,int x) {
    top[u]=t;
    dfn[u]=++cnt;
    id[x]=cnt;
    idd[cnt]=x;
    if(son[u]) dfs2(son[u],t,sonn[u]);
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v,e[i]);
    }
}
int solve(int x,int y) {
    int ret=0;
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) {
            ret+=query(1,dfn[top[x]],dfn[x]);
            x=fa[top[x]];
        }
        else {
            ret+=query(1,dfn[top[y]],dfn[y]);
            y=fa[top[y]];
        }
    }
    return ret+=(dep[x]>dep[y]?query(1,dfn[y],dfn[x])-a[idd[dfn[y]]]:query(1,dfn[x],dfn[y])-a[idd[dfn[x]]]);
}
int main() {
    scanf("%d%d%d",&n,&q,&s);
    for(int i=1;i<n;i++) {
        int u,v;scanf("%d%d%d",&u,&v,&a[i]);
        add_edge(u,v,i);
        add_edge(v,u,i);
    }
    dfs1(s);
    dfs2(s,s,0);
    build(1,1,n);
    for(int i=1;i<=q;i++) {
        int o;scanf("%d",&o);
        if(!o) {
            int x;scanf("%d",&x);
            printf("%d\n",solve(s,x));
            s=x;
        }
        else {
            int x,w;scanf("%d%d",&x,&w);
            update(1,id[x],w);
            a[x]=w;
        }
    }
    return 0;
}