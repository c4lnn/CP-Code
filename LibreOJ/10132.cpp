#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int cnt,to[N*2],val[N*2],nxt[N*2],head[N];
int fa[N],depth[N],sze[N],top[N],son[N],tot,dfn[N];
ll dist[N],ans;
set<pair<int,int> >s;
void addedge(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs1(int u,int t) {
    dfn[u]=++tot;
    depth[u]=t;
    sze[u]=1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==fa[u]) continue;
        fa[v]=u;
        dist[v]=dist[u]+val[i];
        dfs1(v,t+1);
        sze[u]+=sze[v];
        if(sze[v]>sze[son[u]]) son[u]=v;
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
        if(depth[top[a]]>depth[top[b]]) a=fa[top[a]];
        else b=fa[top[b]];
    }
    return depth[a]<depth[b]?a:b;
}
ll path(int a,int b) {
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dfs1(1,1);
    dfs2(1,1);
    cin>>m;
    for(int i=1;i<=m;i++) {
        char c;
        cin>>c;
        if(c=='+') {
            int x;
            cin>>x;
            s.insert({dfn[x],x});
            if(s.size()==1) continue;
            auto l=s.lower_bound({dfn[x],x});
            auto r=s.upper_bound({dfn[x],x});
            if(l==s.begin()) l=--s.end();
            else l--;
            if(r==s.end()) r=s.begin();
            int lnode=(*l).second,rnode=(*r).second;
            ans+=path(lnode,x)+path(x,rnode)-path(lnode,rnode);
        }
        else if(c=='-') {
            int x;
            cin>>x;
            s.erase({dfn[x],x});
            if(s.size()==0) continue;
            auto l=s.lower_bound({dfn[x],x});
            auto r=s.upper_bound({dfn[x],x});
            if(l==s.begin()) l=--s.end();
            else l--;
            if(r==s.end()) r=s.begin();
            int lnode=(*l).second,rnode=(*r).second;
            ans+=-path(lnode,x)-path(x,rnode)+path(lnode,rnode);
        }
        else cout<<ans/2<<endl;
    }
    return 0;
}