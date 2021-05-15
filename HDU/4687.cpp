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
const int N=150;
int u[N],v[N];
int n,m,cnt,fa[N],vis[N],pre[N],dfn[N],match[N];
bool f[N][N],temp[N][N];
queue<int> q;
void init() {
    for(int i=1;i<=n;i++) match[i]=dfn[i]=0;
    cnt=0;
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
        for(int v=1;v<=n;v++) {
            if(!f[u][v]||find(u)==find(v)||vis[v]==2) continue;
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
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=false;
        init();
        for(int i=1;i<=m;i++) {
            scanf("%d%d",&u[i],&v[i]);
            f[u[i]][v[i]]=f[v[i]][u[i]]=true;
        }
        int mx=edmonds();
        VI res;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                temp[i][j]=f[i][j];
        for(int i=1;i<=m;i++) {
            init();
            for(int j=1;j<=n;j++) f[u[i]][j]=f[j][u[i]]=f[v[i]][j]=f[j][v[i]]=false;
            if(edmonds()<mx-1) res.PB(i);
            for(int j=1;j<=n;j++) {
                f[u[i]][j]=temp[u[i]][j];
                f[j][u[i]]=temp[j][u[i]];
                f[v[i]][j]=temp[v[i]][j];
                f[j][v[i]]=temp[j][v[i]];
            }
        }
        printf("%d\n",SZ(res));
        for(int i=0;i<SZ(res);i++) {
            if(i) putchar(' ');
            printf("%d",res[i]);
        }
        puts("");
    }
    return 0;
}