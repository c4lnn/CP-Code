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
const int N=605;
const int INF=0x3f3f3f3f;
int a[N],dist[N],h[N],preu[N],pree[N*5],st[N],id[N];
VI g[N];
struct E {
    int v,c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
vector<E> e;
void init(int n) {
    for(int i=1;i<=n;i++) {
        h[i]=0;
        g[i].clear();
    }
    e.clear();
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
    return MP(flow,cost);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        int s=n+m+1,t=s+1;
        init(t);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            add_edge(m+i,t,a[i],0);
            add_edge(m+i,t,INF,1);
        }
        for(int i=1;i<=m;i++) {
            int u,v;cin>>u>>v;
            add_edge(s,i,1,0);
            add_edge(i,m+u,1,0);
            add_edge(i,m+v,1,0);
            id[i]=SZ(e)-4;
        }
        cout<<mcmf(t,s,t).SE<<'\n';
        for(int i=1;i<=m;i++) st[i]=0;
        for(int i=1;i<=m;i++) if(!e[id[i]].c) {
            st[i]=1;
        }
        for(int i=1;i<=m;i++) cout<<st[i];
        cout<<'\n';
    }
    return 0;
}