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
const int N=25;
const int INF=0x3f3f3f3f;
int n,m,cnt,id[N][N],a[N][N],dist[N*N*2],h[N*N*2],preu[N*N*2],pree[N*N*6];
VI g[N*N*2];
struct E {
    int v;
    int c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
vector<E> e;
void init(int n) {
    for(int i=0;i<SZ(e);i++) pree[i]=0;
    e.clear();
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) h[i]=preu[i]=0;
}
void add_edge(int u,int v,int c,int w) {
    e.EB(v,c,w);
    e.EB(u,0,-w);
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool dijkstra(int n,int s,int t) {
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<PII,VPII,greater<PII>> q;
    dist[s]=0;
    q.emplace(0,s);
    while(SZ(q)) {
        int d=q.top().FI,u=q.top().SE;
        q.pop();
        if(dist[u]!=d) continue;
        for(auto x:g[u]) {
            int v=e[x].v,c=e[x].c,w=e[x].w;
            if(c>0&&dist[v]>dist[u]-h[v]+w+h[u]) {
                dist[v]=dist[u]-h[v]+w+h[u];
                preu[v]=u;
                pree[v]=x;
                q.emplace(dist[v],v);
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
    init(t);
    return MP(flow,cost);
}
int solve1() {
    int s=cnt*2+1,t=s+1;
    for(int i=1;i<=m;i++) add_edge(s,id[1][i],1,0);
    for(int i=1;i<n;i++)
        for(int j=1;j<=m+i-1;j++) {
            add_edge(id[i][j],id[i][j]+cnt,1,a[i][j]);
            add_edge(id[i][j]+cnt,id[i+1][j],1,0);
            add_edge(id[i][j]+cnt,id[i+1][j+1],1,0);
        }
    for(int i=1;i<=m+n-1;i++) {
        add_edge(id[n][i],id[n][i]+cnt,1,a[n][i]);
        add_edge(id[n][i]+cnt,t,1,0);
    }
    return -mcmf(t,s,t).SE;
}
int solve2() {
    int s=cnt+1,t=s+1;
    for(int i=1;i<=m;i++) add_edge(s,id[1][i],1,a[1][i]);
    for(int i=1;i<n;i++)
        for(int j=1;j<=m+i-1;j++) {
            add_edge(id[i][j],id[i+1][j],1,a[i+1][j]);
            add_edge(id[i][j],id[i+1][j+1],1,a[i+1][j+1]);
        }
    for(int i=1;i<=m+n-1;i++) add_edge(id[n][i],t,INF,0);
    return -mcmf(t,s,t).SE;
}
int solve3() {
    int s=cnt+1,t=s+1;
    for(int i=1;i<=m;i++) add_edge(s,id[1][i],1,a[1][i]);
    for(int i=1;i<n;i++)
        for(int j=1;j<=m+i-1;j++) {
            add_edge(id[i][j],id[i+1][j],INF,a[i+1][j]);
            add_edge(id[i][j],id[i+1][j+1],INF,a[i+1][j+1]);
        }
    for(int i=1;i<=m+n-1;i++) add_edge(id[n][i],t,INF,0);
    return -mcmf(t,s,t).SE;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m+i-1;j++) {
            cin>>a[i][j];
            a[i][j]=-a[i][j];
            id[i][j]=++cnt;
        }
    }
    cout<<solve1()<<'\n';
    cout<<solve2()<<'\n';
    cout<<solve3()<<'\n';
    return 0;
}