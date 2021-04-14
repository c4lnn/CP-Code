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
const int N=5e5+5;
vi g[N];
vpii q[N];
int w[N],depth[N],sz[N],son[N],sum[N],sn,ans[N];
void dfs(int u,int d) {
    depth[u]=d;
    sz[u]=1;
    for(auto v:g[u]) {
        dfs(v,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void update(int u) {
    sum[depth[u]]^=(1<<w[u]);
    for(auto v:g[u]) if(v!=sn) update(v);
}
void dsu(int u,bool op) {
    for(auto v:g[u]) {
        if(v==son[u]) continue;
        dsu(v,true);
    }
    if(son[u]) dsu(son[u],false),sn=son[u];
    update(u);
    for(auto x:q[u]) ans[x.se]=sum[x.fi]==(sum[x.fi]&(-sum[x.fi]));
    sn=0;
    if(op) update(u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++) {
        int fa;
        cin>>fa;
        g[fa].pb(i);
    }
    for(int i=1;i<=n;i++) {
        char c;
        cin>>c;
        w[i]=c-'a';
    }
    for(int i=1;i<=m;i++) {
        int x,d;
        cin>>x>>d;
        q[x].pb({d,i});
    }
    dfs(1,1);
    dsu(1,true);
    for(int i=1;i<=m;i++) cout<<(ans[i]?"Yes":"No")<<"\n";
    return 0;
}