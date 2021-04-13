#include <cstdio>
#include <vector>
#define SZ(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
// head
const int N=4e4+5;
int n,m,q;
int dfn[N],sz[N],son[N],fa[N],top[N],dist[N],dep[N];
VPII g[N];
void dfs1(int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI,w=g[u][i].SE;
        if(v==fa[u]) continue;
        fa[v]=u;
        dist[v]=dist[u]+w;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
int LCA(int a,int b) {
    while(top[a]!=top[b]) {
        if(dep[top[a]]>dep[top[b]])  a=fa[top[a]];
        else b=fa[top[b]];
    }
    return dep[a]<dep[b]?a:b;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d%*s",&u,&v,&w);
        g[u].PB(MP(v,w));
        g[v].PB(MP(u,w));
    }
    dfs1(1);
    dfs2(1,1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",dist[a]+dist[b]-2*dist[LCA(a,b)]);
    }
    return 0;
}