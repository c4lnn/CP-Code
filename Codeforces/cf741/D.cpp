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
int n,cnt,l[N],r[N],id[N],w[N],dist[N],sz[N],depth[N],son[N],sn,f[N*10],ans[N];
void dfs(int u,int d) {
    depth[u]=d;
    sz[u]=1;
    l[u]=++cnt;
    id[cnt]=u;
    for(auto v:g[u]) {
        dist[v]=dist[u]^(1<<w[v]);
        dfs(v,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
    r[u]=cnt;
}
void update(int u) {
    if(f[dist[u]]) ans[u]=max(ans[u],f[dist[u]]-depth[u]);
    for(int i=0;i<22;i++) if(f[dist[u]^(1<<i)]) ans[u]=max(ans[u],f[dist[u]^(1<<i)]-depth[u]);
    f[dist[u]]=max(f[dist[u]],depth[u]);
    for(auto v:g[u]) {
        if(v==sn) continue;
        for(int i=l[v];i<=r[v];i++) {
            int x=id[i];
            if(f[dist[x]]) ans[u]=max(ans[u],f[dist[x]]+depth[x]-2*depth[u]);
            for(int j=0;j<22;j++) if(f[dist[x]^(1<<j)]) ans[u]=max(ans[u],f[dist[x]^(1<<j)]+depth[x]-2*depth[u]);
        }
        for(int i=l[v];i<=r[v];i++) f[dist[id[i]]]=max(f[dist[id[i]]],depth[id[i]]);
    }
}
void dsu(int u,bool op) {
    for(auto v:g[u]) if(v!=son[u]) dsu(v,true),ans[u]=max(ans[u],ans[v]);
    if(son[u]) dsu(son[u],false),ans[u]=max(ans[u],ans[son[u]]),sn=son[u];
    update(u);
    sn=0;
    if(op) for(int i=l[u];i<=r[u];i++) f[dist[id[i]]]=0;
}
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        int fa;
        scanf("%d",&fa);
        getchar();
        char c;
        scanf("%c",&c);
        g[fa].pb(i);
        w[i]=c-'a';
    }
    dfs(1,1);
    dsu(1,true);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}