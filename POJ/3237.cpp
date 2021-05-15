#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e4+5;
int n,a[N];
int cnt,sz[N],fa[N],dfn[N],top[N],son[N],sonn[N],id[N],idd[N],dep[N];
int ls[N<<2],rs[N<<2],mx[N<<2],mn[N<<2];
bool lazy[N<<2];
int tot,head[N],to[N<<1],e[N<<1],nxt[N<<1];
void init() {
    for(int i=1;i<=n;i++) {
        head[i]=son[i]=0;
    }
    tot=cnt=0;
}
void add_edge(int u,int v,int i) {
    nxt[++tot]=head[u];
    to[tot]=v;
    e[tot]=i;
    head[u]=tot;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        mn[p]=mx[p]=a[idd[l]];
        lazy[p]=0;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    lazy[p]=0;
}
void push_down(int p) {
    if(lazy[p]) {
        mn[p<<1]=-mn[p<<1],mx[p<<1]=-mx[p<<1];
        swap(mn[p<<1],mx[p<<1]);
        mn[p<<1|1]=-mn[p<<1|1],mx[p<<1|1]=-mx[p<<1|1];
        swap(mn[p<<1|1],mx[p<<1|1]);
        lazy[p<<1]^=1,lazy[p<<1|1]^=1;
        lazy[p]=0;
    }
}
void update1(int p,int x,int v) {
    if(ls[p]==rs[p]) {
        mn[p]=mx[p]=v;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update1(p<<1,x,v);
    else update1(p<<1|1,x,v);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void update2(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) {
        mn[p]=-mn[p];
        mx[p]=-mx[p];
        swap(mn[p],mx[p]);
        lazy[p]^=1;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update2(p<<1,l,r);
    if(r>mid) update2(p<<1|1,l,r);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return mx[p];
    int mid=ls[p]+rs[p]>>1;
    push_down(p);
    if(r<=mid) return query(p<<1,l,r);
    else if(l>mid) return query(p<<1|1,l,r);
    return max(query(p<<1,l,r),query(p<<1|1,l,r));
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
void neg(int x,int y) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) {
            update2(1,dfn[top[x]],dfn[x]);
            x=fa[top[x]];
        }
        else {
            update2(1,dfn[top[y]],dfn[y]);
            y=fa[top[y]];
        }
    }
    if(dep[x]>dep[y]) update2(1,dfn[y]+1,dfn[x]);
    else if(dep[x]<dep[y]) update2(1,dfn[x]+1,dfn[y]);
}
int solve(int x,int y) {
    int ret=0xc0c0c0c0;
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) {
            ret=max(ret,query(1,dfn[top[x]],dfn[x]));
            x=fa[top[x]];
        }
        else {
            ret=max(ret,query(1,dfn[top[y]],dfn[y]));
            y=fa[top[y]];
        }
    }
    if(dep[x]>dep[y]) ret=max(ret,query(1,dfn[y]+1,dfn[x]));
    else if(dep[x]<dep[y]) ret=max(ret,query(1,dfn[x]+1,dfn[y]));
    return ret;
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        init();
        for(int i=1;i<n;i++) {
            int u,v;scanf("%d%d%d",&u,&v,&a[i]);
            add_edge(u,v,i);
            add_edge(v,u,i);
        }
        dfs1(1);
        dfs2(1,1,0);
        build(1,1,n);
        char s[10];
        while(~scanf("%s",s)) {
            if(s[0]=='D') break;
            int x,y;scanf("%d%d",&x,&y);
            if(s[0]=='C') update1(1,id[x],y);
            else if(s[0]=='N') neg(x,y);
            else printf("%d\n",solve(x,y));
        }
    }
    return 0;
}