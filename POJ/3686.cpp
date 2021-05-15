#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define SZ(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int INF=0x3f3f3f3f;
const int N=2600;
int dist[N],h[N],preu[N],pree[N*100];
VI g[N];
struct E {
    int v,c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
vector<E> e;
void add_edge(int u,int v,int c,int w) {
    e.PB(E(v,c,w));
    e.PB(E(u,0,-w));
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool dijkstra(int n,int s,int t) {
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<PII,VPII,greater<PII> > q;
    dist[s]=0;
    q.push(MP(0,s));
    while(SZ(q)) {
        int d=q.top().FI,u=q.top().SE;
        q.pop();
        if(dist[u]!=d) continue;
        for(int i=0;i<SZ(g[u]);i++) {
            int x=g[u][i];
            int v=e[x].v,c=e[x].c,w=e[x].w;
            if(c>0&&dist[v]>dist[u]-h[v]+w+h[u]) {
                dist[v]=dist[u]-h[v]+w+h[u];
                preu[v]=u;
                pree[v]=x;
                q.push(MP(dist[v],v));
            }
        }
    }
    return dist[t]!=INF;
}
PII mcmf(int n,int s,int t) {
    int flow=0,cost=0;
    while(dijkstra(n,s,t)) {
        int c=INF;
        for(int i=1;i<=n;i++) h[i]=min(INF,h[i]+dist[i]);
        for(int u=t;u!=s;u=preu[u]) c=min(c,e[pree[u]].c);
        flow+=c;
        cost+=c*h[t];
        for(int u=t;u!=s;u=preu[u]) {
            e[pree[u]].c-=c;
            e[pree[u]^1].c+=c;
        }
    }
    return MP(flow,cost);
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        int n,m;scanf("%d%d",&n,&m);
        int s=n*m+n+1,t=s+1;
        for(int i=1;i<=t;i++) g[i].clear();
        e.clear();
        for(int i=1;i<=n;i++) add_edge(s,i,1,0);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int x;scanf("%d",&x);
                for(int k=1;k<=n;k++) {
                    add_edge(i,n+(k-1)*m+j,1,k*x);
                }
            }
        }
        for(int i=1;i<=n*m;i++) add_edge(i+n,t,1,0);
        printf("%.6f\n",mcmf(t,s,t).SE*1.0/n);
    }
    return 0;
}