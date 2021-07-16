#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,cnt,fa[N],vis[N],pre[N],dfn[N],match[N],d[N],sum;
vector<int> G[N];
queue<int> q;
void addedge(int u,int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
void init() {
    cnt=sum=0;
    for(int i=1;i<=n+n+m+m;i++) G[i].clear(),match[i]=dfn[i]=0;
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int lca(int u,int v) {
    ++cnt;
    u=find(u),v=find(v);
    while(dfn[u]!=cnt) {
        dfn[u]=cnt;
        u=find(pre[match[u]]);
        if(v) swap(u,v);
    }
    return u;
}
void blossom(int u,int v,int w) {
    while(find(u)!=w) {
        pre[u]=v;
        v=match[u];
        if(vis[v]==2) vis[v]=1,q.push(v);
        if(find(u)==u) fa[u]=w;
        if(find(v)==v) fa[v]=w;
        u=pre[v];
    }
}
bool aug(int s) {
    for(int i=1;i<=n;i++) fa[i]=i,vis[i]=pre[i]=0;
    while(!q.empty()) q.pop();
    q.push(s);
    vis[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto v:G[u]) {
            if(find(u)==find(v)||vis[v]==2) continue;
            if(!vis[v]) {
                vis[v]=2,pre[v]=u;
                if(!match[v]) {
                    for(int x=v,lst;x;x=lst) lst=match[pre[x]],match[x]=pre[x],match[pre[x]]=x;
                    return true;
                }
                vis[match[v]]=1,q.push(match[v]);
            }
            else {
                int w=lca(u,v);
                blossom(u,v,w);
                blossom(v,u,w);
            }
        }
    }
    return false;
}
int Edmonds() {
    int res=0;
    for(int i=1;i<=n;i++) if(!match[i]) res+=aug(i);
    return res;
}
int main() {
    while(~scanf("%d%d",&n,&m)) {
        init();
        for(int i=1;i<=n;i++) scanf("%d",&d[i]),sum+=d[i];
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,n+n+i);
            addedge(n+n+i,n+n+i+m);
            addedge(n+n+i+m,v);
            if(d[u]==2) addedge(u+n,n+n+i);
            if(d[v]==2) addedge(n+n+i+m,v+n);
        }
        n=n+n+m+m;
        puts(sum+m*2==Edmonds()*2?"Yes":"No");
    }
    return 0;
}