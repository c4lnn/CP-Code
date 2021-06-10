#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
int w[N],s[N],t[N];
int cnt,to[N*2],nxt[N*2],head[N];
int fa[N],sz[N],d[N],top[N],son[N];
vector<pair<int,int> >p[N];
int c[N*2];
int ans[N];
void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs1(int u,int t) {
    d[u]=t;
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v,t+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
int lca(int a,int b) {
    while(top[a]!=top[b]) {
        if(d[top[a]]>d[top[b]]) a=fa[top[a]];
        else b=fa[top[b]];
    }
    return d[a]<d[b]?a:b;
}
void dif1() {
    for(int i=1;i<=m;i++) {
        int LCA=lca(s[i],t[i]);
        p[s[i]].push_back({d[s[i]],1});
        p[fa[LCA]].push_back({d[s[i]],-1});
    }
}
void dif2() {
    for(int i=1;i<=m;i++) {
        int LCA=lca(s[i],t[i]);
        p[t[i]].push_back({d[s[i]]-2*d[LCA],1});
        p[LCA].push_back({d[s[i]]-2*d[LCA],-1});
    }
}
void dfs_solve1(int u) {
    int tot=c[w[u]+d[u]];
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        dfs_solve1(v);
    }
    for(auto x:p[u]) c[x.first]+=x.second;
    ans[u]+=c[w[u]+d[u]]-tot;
}
void dfs_solve2(int u) {
    int tot=c[w[u]-d[u]+n];
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        dfs_solve2(v);
    }
    for(auto x:p[u]) c[x.first+n]+=x.second;
    ans[u]+=c[w[u]-d[u]+n]-tot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++) cin>>s[i]>>t[i];
    dif1();
    dfs_solve1(1);
    for(int i=1;i<=n;i++) p[i].clear();
    memset(c,0,sizeof c);
    dif2();
    dfs_solve2(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}