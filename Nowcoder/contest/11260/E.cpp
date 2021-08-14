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
int a[N],f[N][20],sz[N],dfn[N],cnt1,rt[N],ls[N<<5],rs[N<<5],sum[N<<5],cnt2;
VI g[N];
void update(int &p,int q,int L,int R,int x) {
    p=++cnt2;
    ls[p]=ls[q],rs[p]=rs[q],sum[p]=sum[q]+1;
    if(L==R) return;
    int mid=L+R>>1;
    if(x<=mid) update(ls[p],ls[q],L,mid,x);
    else update(rs[p],rs[q],mid+1,R,x);
}
int query(int p,int L,int R,int l,int r) {
    if(L>=l&&R<=r) return sum[p];
    int mid=L+R>>1;
    if(r<=mid) return query(ls[p],L,mid,l,r);
    if(l>mid) return query(rs[p],mid+1,R,l,r);
    return query(ls[p],L,mid,l,mid)+query(rs[p],mid+1,R,mid+1,r);
}
void dfs(int u,int fa) {
    dfn[u]=++cnt1;
    sz[u]=1;
    update(rt[cnt1],rt[cnt1-1],1,1e9,a[u]);
    for(auto v:g[u]) if(v!=fa) {
        f[v][0]=u;
        for(int i=1;i<18;i++) f[v][i]=f[f[v][i-1]][i-1];
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int find(int x,int l,int r) {
    if(a[x]<l||a[x]>r) return -1;
    for(int i=17;~i;i--) if(a[f[x][i]]<=r) {
        x=f[x][i];
    }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v),g[v].PB(u);
    }
    a[0]=1e9+7;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        int x,l,r;cin>>x>>l>>r;
        x=find(x,l,r);
        if(x==-1) cout<<0<<'\n';
        else cout<<query(rt[dfn[x]+sz[x]-1],1,1e9,l,r)-query(rt[dfn[x]-1],1,1e9,l,r)<<'\n';
    }
    return 0;
}