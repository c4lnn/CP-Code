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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=300;
int n,m,cnt,fa[N],vis[N],pre[N],dfn[N],match[N];
vector<int> g[N];
queue<int> q;
void addEdge(int u,int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int LCA(int u,int v) {
    ++cnt;
    u=find(u),v=find(v);
    while(dfn[u]!=cnt) {
        dfn[u]=cnt;
        u=find(pre[match[u]]);
        if(v) swap(u,v);
    }
    return u;
}
void blossom(int u,int v,int lca) {
    while(find(u)!=lca) {
        pre[u]=v;
        v=match[u];
        if(vis[v]==2) vis[v]=1,q.push(v);
        if(find(u)==u) fa[u]=lca;
        if(find(v)==v) fa[v]=lca;
        u=pre[v];
    }
}
bool aug(int s) {
    for(int i=1;i<=n;i++) fa[i]=i,vis[i]=pre[i]=0;
    while(q.size()) q.pop();
    q.push(s);
    vis[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(find(u)==find(v)||vis[v]==2) continue;
            if(!vis[v]) {
                vis[v]=2,pre[v]=u;
                if(!match[v]) {
                    for(int x=v,lst;x;x=lst) {
                        lst=match[pre[x]];
                        match[x]=pre[x];
                        match[pre[x]]=x;
                    }
                    return true;
                }
                vis[match[v]]=1,q.push(match[v]);
            }
            else {
                int lca=LCA(u,v);
                blossom(u,v,lca);
                blossom(v,u,lca);
            }
        }
    }
    return false;
}
int edmonds() {
  int res=0;
  for(int i=1;i<=n;i++) if(!match[i]) res+=aug(i);
  return res;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d",&n);
    int u,v;
    while(~scanf("%d%d",&u,&v)) addEdge(u,v);
    printf("%d\n",edmonds()<<1);
    for(int i=1;i<=n;i++) {
        if(!match[i]) continue;
        printf("%d %d\n",i,match[i]);
        match[match[i]]=0;
    }
    return 0;
}