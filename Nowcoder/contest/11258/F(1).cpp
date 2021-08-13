// 树上划窗 & 线段树
// O(nlog(n))
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
const int N=3e5+5;
int res,cnt,dfn[N],sz[N],dep[N],ls[N<<2],rs[N<<2],mx[N<<2],laz[N<<2];
VI g1[N],g2[N];
deque<int> q;
void init(int n) {
    cnt=res=0;
    for(int i=1;i<=n;i++) g1[i].clear(),g2[i].clear();
    while(SZ(q)) q.pop_back();
}
void dfs1(int u,int fa) {
    dfn[u]=++cnt;
    sz[u]=1;
    for(auto v:g2[u]) if(v!=fa) {
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
void pushdown(int p) {
    if(laz[p]) {
        mx[p<<1]+=laz[p],mx[p<<1|1]+=laz[p];
        laz[p<<1]+=laz[p],laz[p<<1|1]+=laz[p];
        laz[p]=0;
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    mx[p]=laz[p]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        mx[p]+=v;
        laz[p]+=v;
        return;
    }
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void dfs2(int u,int fa) {
    dep[u]=dep[fa]+1;
    update(1,dfn[u],dfn[u]+sz[u]-1,1);
    q.PB(u);
    int t=-1;
    if(mx[1]==1) res=max(res,dep[u]-dep[q.front()]+1);
    else if(dep[u]-dep[q.front()]+1>res) {
        t=q.front();
        update(1,dfn[t],dfn[t]+sz[t]-1,-1);
        q.pop_front();
    }
    for(auto v:g1[u]) if(v!=fa) {
        dfs2(v,u);
    }
    if(t!=-1) {
        q.push_front(t);
        update(1,dfn[t],dfn[t]+sz[t]-1,1);
    }
    update(1,dfn[u],dfn[u]+sz[u]-1,-1);
    q.pop_back();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        init(n);
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g1[u].PB(v);
            g1[v].PB(u);
        }
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g2[u].PB(v);
            g2[v].PB(u);
        }
        dfs1(1,0);
        build(1,1,n);
        dfs2(1,0);
        cout<<res<<'\n';
    }
    return 0;
}