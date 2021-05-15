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
const int N=1005;
int n,m,s,t,dist[N],d[N],cur[N];
bool st[N];
VI gg[N];
VPII g[N],e;
void dijkstra() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f,st[i]=false;
    priority_queue<PII,VPII,greater<PII>> q;
    q.emplace(0,s);
    dist[s]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI,w=x.SE;
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.emplace(dist[v],v);
            }
        }
    }
}
void addedge(int u,int v,int c) {
    e.EB(v,c);
    e.EB(u,0);
    gg[u].PB(SZ(e)-2);
    gg[v].PB(SZ(e)-1);
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    q.push(s);
    d[s]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto x:gg[u]) {
            int v=e[x].FI,c=e[x].SE;
            if(d[v]||c<=0) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    return d[t];
}
int dfs(int u,int a) {
    if(u==t) return a;
    int flow=0,f;
    for(int &i=cur[u];i<SZ(gg[u]);i++) {
        int v=e[gg[u][i]].FI,&c=e[gg[u][i]].SE;
        if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c)))<=0) continue;
        c-=f;
        e[gg[u][i]^1].FI+=f;
        a-=f;
        flow+=f;
        if(!a) break;
    }
    return flow;
}
int dinic() {
    int flow=0;
    while(bfs()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        flow+=dfs(s,0x3f3f3f3f);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) g[i].clear(),gg[i].clear();
        e.clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==v) continue;
            g[u].EB(v,w);
        }
        scanf("%d%d",&s,&t);
        dijkstra();
        for(int u=1;u<=n;u++)
            for(auto x:g[u]) {
                int v=x.FI,w=x.SE;
                if(dist[u]+w==dist[v])
                    addedge(u,v,1);
            }
        printf("%d\n",dinic());
    }
    return 0;
}