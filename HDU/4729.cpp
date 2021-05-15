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
void dfs1(int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for(auto x:g[u]) {
        int v=x.FI;
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    dfn[u]=++cnt;
    if(son[u]) dfs2(son[u],t);
    for(auto x:g[u]) {
        int v=x.FI;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
void solve(int a,int b) {
    while(top[a]!=top[b]) {
        if(dep[a]>dep[b]) {

            a=fa[top[a]];
        }
        else {

            b=fa[top[b]];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=1;i<n;i++) {
            int u,v,w;cin>>u>>v>>w;
            g[u].EB(v,w);
            g[v].EB(u,w);
        }
        for(int i=1;i<=m;i++) {
            int s,t,k,a,b;cin>>s>>t>>k>>a>>b;
        }
    }
    return 0;
}