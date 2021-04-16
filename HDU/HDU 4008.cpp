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
const int INF=0x3f3f3f3f;
const int N=1e5+5;
int n,m,cnt,sz[N],dfn[N],son[N],dep[N],fa[N],top[N],id[N],mn[N][2];
int w[N<<2],ls[N<<2],rs[N<<2];
VI g[N];
void init() {
    for(int i=1;i<=n;i++) {
        son[i]=0;
        mn[i][0]=mn[i][1]=INF;
        g[i].clear();
    }
    cnt=0;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        w[p]=id[l];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=min(w[p<<1],w[p<<1|1]);
}
int query(int p,int l,int r) {
    if(l>r) return INF;
    if(ls[p]>=l&&rs[p]<=r) return w[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return min(query(p<<1,l,r),query(p<<1|1,l,r));
}
void dfs1(int u) {
    sz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for(auto v:g[u]) if(v!=fa[u]) {
        fa[v]=u;
        mn[v][0]=u;
        if(v<mn[u][0]) mn[u][1]=mn[u][0],mn[u][0]=v;
        else if(v<mn[u][1]) mn[u][1]=v;
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
PII solve(int a,int b) {
    if(sz[a]==1) return MP(INF,INF);
    int t=a,tt;
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) a=fa[top[a]];
        else {
            tt=dfn[top[b]];
            b=fa[top[b]];
        }
    }
    if(dep[a]<=dep[b]&&a==t) {
        int sn=a==b?id[tt]:id[dfn[a]+1];
        if(n-sz[sn]-1==0) return MP(INF,INF);
        PII ret;
        ret.FI=sn==mn[a][0]?mn[a][1]:mn[a][0];
        int l=a==b?tt:dfn[a]+1,r=l+sz[id[l]]-1;
        ret.SE=min({query(1,1,dfn[a]-1),query(1,dfn[a]+1,l-1),query(1,r+1,n)});
        return ret;
    }
    return MP(fa[t]==mn[t][0]?mn[t][1]:mn[t][0],query(1,dfn[t]+1,dfn[t]+sz[t]-1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m;
        init();
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v),g[v].PB(u);
        }
        dfs1(1);dfs2(1,1);
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            int rt,u;cin>>rt>>u;
            PII res=solve(u,rt);
            if(res.FI==INF) cout<<"no answers!"<<'\n';
            else cout<<res.FI<<' '<<res.SE<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}