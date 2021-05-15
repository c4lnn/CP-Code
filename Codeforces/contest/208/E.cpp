#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
//head
const int N=1e5+5;
map<int,int>mp;
int n,m,dep[N],sz[N],son[N],sum[N],ans[N],f[N][20],sn;
vi g[N];
vpii q[N];
void dfs(int u) {
    sz[u]=1;
    for(auto v:g[u]) {
        dep[v]=dep[u]+1;
        f[v][0]=u;
        for(int i=1;i<20;i++) f[v][i]=f[f[v][i-1]][i-1];
        dfs(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
int find(int u,int k) {
    while(int t=k&-k) u=f[u][mp[t]],k-=t;
    return u;
}
void update(int u,int val) {
    sum[dep[u]]+=val;
    for(auto v:g[u]) {
        if(v==sn) continue;
        update(v,val);
    }
}
void dsu(int u,bool op) {
    for(auto v:g[u]) {
        if(v==son[u]) continue;
        dsu(v,true);
    }
    if(son[u]) dsu(son[u],false),sn=son[u];
    update(u,1);
    for(auto x:q[u]) ans[x.se]=sum[x.fi]-1;
    sn=0;
    if(op) update(u,-1);
}
int main() {
    for(int i=0;i<20;i++) mp[1<<i]=i;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int fa;
        scanf("%d",&fa);
        g[fa].pb(i);
    }
    scanf("%d",&m);
    dfs(0);
    for(int i=1;i<=m;i++) {
        int v,p;
        scanf("%d%d",&v,&p);
        int t=find(v,p);
        if(t==0) ans[i]=0;
        else q[t].pb({dep[v],i});
    }
    dsu(0,true);
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}