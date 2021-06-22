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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e6+5;
int sz[N],dep[N],son[N],fa[N],top[N],dist[N];
VI g[N];
void dfs1(int u) {
    sz[u]=1;
    for(auto v:g[u]) {
        if(v==fa[u]) continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(auto v:g[u]) {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int LCA(int u,int v) {
    while(top[u]!=top[v]) {
        if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
        else v=fa[top[v]];
    }
    return dep[u]<dep[v]?u:v;
}
void bfs(int a,int b) {
    queue<int> q;
    q.push(a);
    q.push(b);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(v==a||v==b||dist[v]) continue;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    int a,b;
    cin>>a>>b;
    dfs1(a);
    dfs2(a,a);
    bfs(a,b);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        int u,v;
        cin>>u>>v;
        cout<<min(dep[u]+dep[v]-2*dep[LCA(u,v)],dist[u]+dist[v])<<'\n';
    }
    return 0;
}