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
//head
const int N=2005;
const int M=25005;
const int INF=0x3f3f3f3f;
int a[N],dist[N],h[N],preu[N],pree[M];
bool st[N];
struct E {
    int v;
    int c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
vector<E> e;
VI g[N];
void add_edge(int u,int v,int c,int w) {
    e.EB(v,c,w);
    e.EB(u,0,-w);
    g[u].PB(e.size()-2);
    g[v].PB(e.size()-1);
}
bool dijkstra(int n,int s,int t) {
    for(int i=1;i<=n;i++) dist[i]=INF,st[i]=false;
    priority_queue<PII,VPII,greater<PII>> q;
    dist[s]=0;
    q.emplace(0,s);
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=e[x].v,c=e[x].c,w=e[x].w;
            if(!st[v]&&c>0&&dist[v]>dist[u]-h[v]+w+h[u]) {
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
        for(int i=1;i<=n;i++) h[i]+=dist[i];
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
    int n,p,t1,c1,t2,c2;
    cin>>n>>p>>t1>>c1>>t2>>c2;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=n+n+1,t=s+1;
    for(int i=1;i<=n;i++) add_edge(s,i,a[i],0);
    for(int i=1;i<=n;i++) add_edge(s,i+n,INF,p);
    for(int i=1;i<=n;i++) add_edge(i+n,t,a[i],0);
    for(int i=1;i<n;i++) add_edge(i,i+1,INF,0);
    for(int i=1;i+t1<=n;i++) add_edge(i,i+n+t1,INF,c1);
    for(int i=1;i+t2<=n;i++) add_edge(i,i+n+t2,INF,c2);
    cout<<mcmf(t,s,t).SE<<'\n';
    return 0;
}