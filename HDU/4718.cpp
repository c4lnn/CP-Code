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
int cnt,fa[N],sz[N],dep[N],son[N],top[N],dfn[N],id[N],a[N];
VI g[N];
struct R {
    int ls,rs;
    int up_len;
    int down_len;
    PII l_up;
    PII l_down;
    PII r_up;
    PII r_down;
    void init() {
        ls=rs=up_len=down_len=0;
        l_up=l_down=r_up=r_down=MP(0,0);
    }
}node[N<<2];
void init(int n) {
    for(int i=1;i<=n;i++) {
        son[i]=0;
        g[i].clear();
    }
    cnt=0;
}
void push_up(R &a,R b,R c) {
    a.ls=b.ls,a.rs=c.rs;
    a.up_len=max({b.up_len,c.up_len,b.r_up.FI<c.l_up.FI?b.r_up.SE+c.l_up.SE:0});
    a.down_len=max({b.down_len,c.down_len,b.r_down.FI>c.l_down.FI?b.r_down.SE+c.l_down.SE:0});
    a.l_up.FI=b.l_up.FI;
    a.l_up.SE=b.l_up.SE+(b.r_up.SE==b.rs-b.ls+1&&b.r_up.FI<c.l_up.FI?c.l_up.SE:0);
    a.l_down.FI=b.l_down.FI;
    a.l_down.SE=b.l_down.SE+(b.r_down.SE==b.rs-b.ls+1&&b.r_down.FI>c.l_down.FI?c.l_down.SE:0);
    a.r_up.FI=c.r_up.FI;
    a.r_up.SE=c.r_up.SE+(c.l_up.SE==c.rs-c.ls+1&&b.r_up.FI<c.l_up.FI?b.r_up.SE:0);
    a.r_down.FI=c.r_down.FI;
    a.r_down.SE=c.r_down.SE+(c.l_down.SE==c.rs-c.ls+1&&b.r_down.FI>c.l_down.FI?b.r_down.SE:0);
}
void build(int p,int l,int r) {
    if(l==r) {
        node[p].ls=node[p].rs=l;
        node[p].up_len=node[p].down_len=1;
        node[p].l_up=node[p].l_down=node[p].r_up=node[p].r_down=MP(a[id[l]],1);
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(node[p],node[p<<1],node[p<<1|1]);
}
R query(int p,int l,int r) {
    if(node[p].ls>=l&&node[p].rs<=r) return node[p];
    int mid=node[p].ls+node[p].rs>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    R ret=query(p<<1,l,r);
    push_up(ret,ret,query(p<<1|1,l,r));
    return ret;
}
void dfs1(int u) {
    sz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for(auto v:g[u]) {
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
    for(auto v:g[u]) if(v!=son[u]) {
        dfs2(v,v);
    }
}
int solve(int a,int b) {
    R p,q;
    p.init(),q.init();
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]]) {
            push_up(p,query(1,dfn[top[a]],dfn[a]),p);
            a=fa[top[a]];
        }
        else {
            push_up(q,query(1,dfn[top[b]],dfn[b]),q);
            b=fa[top[b]];
        }
    }
    if(dep[a]>dep[b]) push_up(p,query(1,dfn[b],dfn[a]),p);
    else push_up(q,query(1,dfn[a],dfn[b]),q);
    return max({p.down_len,q.up_len,p.l_down.FI<q.l_up.FI?p.l_down.SE+q.l_up.SE:0});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        init(n);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++) {
            int f;cin>>f;
            fa[i]=f;
            g[f].PB(i);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        int q;cin>>q;
        cout<<"Case #"<<cs<<":\n";
        for(int i=1;i<=q;i++) {
            int a,b;cin>>a>>b;
            cout<<solve(a,b)<<'\n';
        }
        if(cs!=T) cout<<'\n';
    }
    return 0;
}