// 主席树
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
int n,res,cnt,dfn[N],sz[N],dep[N];
int t,rt[N],ls[N<<6],rs[N<<6],mx[N<<6],laz[N<<6];
VI g1[N],g2[N];
void init(int n) {
    for(int i=1;i<=n;i++) g1[i].clear(),g2[i].clear();
    for(int i=1;i<=t;i++) ls[i]=rs[i]=mx[i]=laz[i]=0;
    cnt=t=0;
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
        if(!ls[p]) ls[p]=++t;
        if(!rs[p]) rs[p]=++t;
        mx[ls[p]]=mx[rs[p]]=laz[ls[p]]=laz[rs[p]]=laz[p];
        laz[p]=0;
    }
}
int update(int &p,int q,int L,int R,int l,int r,int v) {
    p=++t;
    ls[p]=ls[q],rs[p]=rs[q],mx[p]=v;
    if(L>=l&&R<=r) {
        int len=v-mx[q];
        ls[p]=rs[p]=0;
        laz[p]=v;
        return len;
    }
    pushdown(q);
    int mid=L+R>>1;
    if(r<=mid) return update(ls[p],ls[q],L,mid,l,r,v);
    if(l>mid) return update(rs[p],rs[q],mid+1,R,l,r,v);
    return min(update(ls[p],ls[q],L,mid,l,mid,v),update(rs[p],rs[q],mid+1,R,mid+1,r,v));
}
void dfs2(int u,int fa,int len) {
    dep[u]=dep[fa]+1;
    len=min(len+1,update(rt[u],rt[fa],1,n,dfn[u],dfn[u]+sz[u]-1,dep[u]));
    res=max(res,len);
    for(auto v:g1[u]) if(v!=fa) {
        dfs2(v,u,len);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n;
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
        res=0;
        dfs2(1,0,0);
        cout<<res<<'\n';
    }
    return 0;
}