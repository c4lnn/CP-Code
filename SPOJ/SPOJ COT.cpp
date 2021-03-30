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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int n,m,a[N],dep[N],sz[N],son[N],top[N],fa[N];
int rt[N],ls[N<<5],rs[N<<5],w[N<<5],cnt;
VI g[N],b;
int build(int l,int r) {
    int p=++cnt;
    if(l==r) return p;
    int mid=l+r>>1;
    ls[p]=build(l,mid);
    rs[p]=build(mid+1,r);
    return p;
}
int insert(int now,int l,int r,int x) {
    int p=++cnt;
    ls[p]=ls[now],rs[p]=rs[now],w[p]=w[now];
    if(l==r) {w[p]++;return p;}
    int mid=l+r>>1;
    if(x<=mid) ls[p]=insert(ls[now],l,mid,x);
    else rs[p]=insert(rs[now],mid+1,r,x);
    w[p]=w[ls[p]]+w[rs[p]];
    return p;
}
int query(int p,int q,int a,int b,int l,int r,int k) {
    if(l==r) return l;
    int mid=l+r>>1;
    int lsum=w[ls[p]]+w[ls[q]]-w[ls[a]]-w[ls[b]];
    if(k<=lsum) return query(ls[p],ls[q],ls[a],ls[b],l,mid,k);
    else return query(rs[p],rs[q],rs[a],rs[b],mid+1,r,k-lsum);
}
void dfs1(int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    rt[u]=insert(rt[fa[u]],1,SZ(b),a[u]);
    for(auto v:g[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(auto v:g[u]) {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int LCA(int a,int b) {
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) a=fa[top[a]];
        else b=fa[top[b]];
    }
    return dep[a]<dep[b]?a:b;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b.PB(a[i]);
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(ALL(b),a[i])-b.begin()+1;
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    rt[0]=build(1,SZ(b));
    dfs1(1);
    dfs2(1,1);
    for(int i=1;i<=m;i++) {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int lca=LCA(u,v);
        printf("%d\n",b[query(rt[u],rt[v],rt[lca],rt[fa[lca]],1,SZ(b),k)-1]);
    }
    return 0;
}