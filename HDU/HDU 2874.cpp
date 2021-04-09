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
const int N=1e4+5;
int n,m,c;
int fa[N],sz[N],depth[N],top[N],son[N],dist[N],rt[N];
int nxt[N<<1],val[N<<1],to[N<<1],head[N],cnt;
void add_edge(int u,int v,int w) {
    nxt[++cnt]=head[u];
    val[cnt]=w;
    to[cnt]=v;
    head[u]=cnt;
}
void dfs1(int u,int t) {
    sz[u]=1;
    rt[u]=t;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i],w=val[i];
        if(v==fa[u]) continue;
        dist[v]=w+dist[u];
        depth[v]=depth[u]+1;
        fa[v]=u;
        dfs1(v,t);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int a,int b) {
    while(top[a]!=top[b]) {
        if(depth[top[a]]>depth[top[b]]) a=fa[top[a]];
        else b=fa[top[b]];
    }
    return depth[a]<depth[b]?a:b;
}
int main() {
    while(~scanf("%d%d%d",&n,&m,&c)) {
        for(int i=1;i<=n;i++) fa[i]=sz[i]=top[i]=son[i]=depth[i]=dist[i]=head[i]=rt[i]=0;
        cnt=0;
        for(int i=1;i<=m;i++) {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        for(int i=1;i<=n;i++) if(!sz[i]) dfs1(i,i);
        for(int i=1;i<=n;i++) if(!top[i]) dfs2(i,i);
        for(int i=1;i<=c;i++) {
            int a,b;scanf("%d%d",&a,&b);
            if(rt[a]!=rt[b]) puts("Not connected");
            else printf("%d\n",dist[a]+dist[b]-2*dist[lca(a,b)]);
        }
    }
    return 0;
}